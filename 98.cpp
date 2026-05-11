#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <tuple>
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
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

    bool valid(TreeNode* node, long left, long right) {
        if (!node) return true;

        if (!(left < node->val && node->val < right))
            return false;

        return valid(node->left, left, node->val) && valid(node->right, node->val, right);
    }

private:
    bool isValidBFS(TreeNode* root) {
        if (!root) return true;

        queue<tuple<TreeNode*, long, long>> q;
        q.push({root, LONG_MIN, LONG_MAX});

        while (!q.empty()) {
            auto [node, left, right] = q.front();
            q.pop();

            if (!(left < node->val && node->val < right))
                return false;

            if (node->left)
                q.push({node->left, left, node->val});

            if (node->right)
                q.push(make_tuple(node->right, node->val, right));
        }

        return true;
    }
};
