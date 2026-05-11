#include <map>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;

        while (!q.empty()) {
            TreeNode* cur = q.front();
            if (cur->val == start) res = cur;
            q.pop();

            if (cur->left) {
                mp[cur->left] = cur;
                q.push(cur->left);
            }

            if (cur->right) {
                mp[cur->right] = cur;
                q.push(cur->right);
            }
        }

        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        TreeNode* tar = markParents(root, mp, start);

        queue<TreeNode*> q;
        q.push(tar);

        map<TreeNode*, int> vis;
        vis[tar] = 1;
        int res = 0;

        while (!q.empty()) {
            int sz = q.size();
            int flag = 0;
            for (int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    flag = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }

                if (node->right && !vis[node->right]) {
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if (mp[node] && !vis[mp[node]]) {
                    flag = 1;
                    vis[mp[node]] = 1;
                    q.push(mp[node]);
                }
            }

            if (flag) res++;
        }

        return res;
    }

private:
    int res;
    
    int findheight(TreeNode* root, int start){
        if (!root) return 0;
        
        int lh = findheight(root->left, start);
        int rh = findheight(root->right, start);
        
        if (root->val == start) {
            res = max(lh, rh);
            return -1;
        }

        else if (lh<0 || rh<0) {
            res = max(res, abs(lh) + abs(rh));
            return min(lh, rh) - 1;
        }
        
        return max(lh, rh) + 1;
    }

    int optimalSol(TreeNode* root, int start) {
        res = 0;
        findheight(root, start);
        return res;
    }
};
