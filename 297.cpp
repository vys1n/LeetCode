#include <bits/stdc++.h>
#include <queue>
#include <sstream>
#include <string>
#include <strstream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "N";
        string res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node)
                res += "N,";
            else{
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return res;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');

        if (val == "N") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (getline(ss, val, ',')) {
            TreeNode* node = q.front();
            q.pop();

            if (val != "N") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            getline(ss, val, ',');

            if (val != "N") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }

        return root;
    }

private:
    string DFSserialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res, ",");
    }

    TreeNode* DFSdeserialize(string data) {
        vector<string> vals = split(data, ',');
        int i=0;
        return dfsDeserialize(vals, i);
    }

    void dfsSerialize(TreeNode* node, vector<string>& res) {
        if (!node) {
            res.push_back("N");
            return;
        }

        res.push_back(to_string(node->val));
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    TreeNode* dfsDeserialize(vector<string> &vals, int &i) {
        if (vals[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;

        node->left = dfsDeserialize(vals, i);
        node->right = dfsDeserialize(vals, i);

        return node;
    }

    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (const auto&i : v) {
            if (&i != &v[0])
                s << delim;
            s << i;
        }

        return s.str();
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;

        while (getline(ss, item, delim))
            elems.push_back(item);

        return elems;
    }
};
