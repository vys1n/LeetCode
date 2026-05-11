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
    TreeNode* rec(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        if (val > root->val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);

        return root;
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);

        TreeNode* cur = root;

        while (true) {
            if (val > cur->val) {
                if (!cur->right) {
                    cur->right = new TreeNode(val);
                    return root;
                }

                cur = cur->right;
            }

            else {
                if (!cur->left) {
                    cur->left = new TreeNode(val);
                    return root;
                }

                cur = cur->left;
            }
        }
    }
};
