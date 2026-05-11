#include <bits/stdc++.h>
#include <queue>
#include <sys/types.h>
#include <tuple>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int res = 0;
        int prevLevel = 0, prevNum = 1;
        
        queue<tuple<TreeNode*, uint, int>> q;
        q.push({root, 1, 0});

        while (!q.empty()) {
            auto [node, num, level] = q.front();
            q.pop();

            if (level > prevLevel) {
                prevLevel = level;
                prevNum = num;
            }

            res = max(res, int(num - prevNum) + 1);

            if (node->left)
                q.push({node->left, 2 * num, level + 1});

            if (node->right)
                q.push({node->right, 2 * num + 1, level + 1});
        }

        return res;
    }
};
