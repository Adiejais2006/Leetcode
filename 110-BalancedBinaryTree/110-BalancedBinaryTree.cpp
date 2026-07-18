// Last updated: 7/18/2026, 2:06:29 PM
class Solution {
    int height(TreeNode* root) {
        if (root == NULL) return 0;

        return 1 + max(height(root->left), height(root->right));
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(lh - rh) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};