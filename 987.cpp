#include <bits/stdc++.h>
#include <queue>
#include <set>
#include <vector>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            TreeNode* node = cur.first;
            int x = cur.second.first;   // col (index)
            int y = cur.second.second;  // row (level)
            nodes[x][y].insert(node->val);

            if (node->left)
                q.push({node->left, {x-1, y+1}});
            if (node->right)
                q.push({node->right, {x+1, y+1}});
        }

        vector<vector<int>> res;
        for (auto i : nodes) {
            vector<int> col;
            for (auto j : i.second) {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }

            res.push_back(col);
        }

        return res;
    }
};
