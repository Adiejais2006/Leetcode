// Last updated: 7/18/2026, 2:03:17 PM

class Solution {
    bool post(TreeNode* root) {
        if (!root)
            return false;
        bool left = post(root->left);
        bool right = post(root->right);
        if (left == false)
            root->left = nullptr;
        if (right == false)
            root->right = nullptr;
        return root->val == 1 || left || right;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!post(root))
            return nullptr;
        return root;
    }
};