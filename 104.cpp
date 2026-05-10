#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <utility>
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
private:
    int recursiveDFS(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    int iterativeDFS(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int res = 0;

        while (!st.empty()) {
            pair<TreeNode*, int> cur = st.top();
            st.pop();

            TreeNode* node = cur.first;
            int depth = cur.second;

            if (node) {
                res = max(res, depth);
                st.push({node->left, depth+1});
                st.push({node->right, depth+1});
            }
        }

        return res;
    }

public:
    int maxDepth(TreeNode* root) {
        // BFS
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int i=0; i<sz; i++) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
           
            level++;
        }

        return level;
    }
};
