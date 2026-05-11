#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (max(p->val, q->val) < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (min(p->val, q->val) > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        while (cur) {
            if (p->val > cur->val && q->val > cur->val)
                cur = cur->right;
            else if (p->val < cur->val && q->val < cur->val)
                cur = cur->left;
            else
                return cur;
        }

        return nullptr;
    }
};
