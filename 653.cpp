#include <bits/stdc++.h>
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
    void inorder(TreeNode* root, vector<int>& aux) {
        if (!root) return;

        inorder(root->left, aux);
        aux.push_back(root->val);
        inorder(root->right, aux);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> aux;
        inorder(root, aux);

        int l=0, r = aux.size()-1;

        while (l<r) {
            int cur = aux[l] + aux[r];

            if (cur == k) return true;
            else if (cur < k) l++;
            else r--;
        }

        return false;
    }
};
