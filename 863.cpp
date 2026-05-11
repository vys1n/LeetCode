#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void markParents(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }

            if (cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
   
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, target, parent);

        queue<TreeNode*> q;
        q.push(target);
        
        unordered_map<TreeNode*, bool> vis;
        vis[target] = true;

        int level = 0;

        while (!q.empty()) {
            if (level == k) break;
            level++;

            int sz = q.size();
            for (int i=0; i<sz; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left && !vis[cur->left]) {
                    q.push(cur->left);
                    vis[cur->left] = true;
                }

                if (cur->right && !vis[cur->right]) {
                    q.push(cur->right);
                    vis[cur->right] = true;
                }

                if (parent[cur] && !vis[parent[cur]]) {
                    q.push(parent[cur]);
                    vis[parent[cur]] = true;
                }
            }
        }

        vector<int> res;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            res.push_back(cur->val);
        }

        return res;
    }
};
