// Last updated: 7/18/2026, 2:04:34 PM

class Solution {
    TreeNode* helper(TreeNode* node) {
        if (node->left == nullptr)
            return node->right;
        if (node->right == nullptr)
            return node->left;
        TreeNode* rightpart = node->right;
        TreeNode* last = rightmost(node->left);
        last->right = rightpart;
        return node->left;
    }
    TreeNode* rightmost(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (root->val == key) {
            return helper(root);
        }
        TreeNode* dummy = root;
        while (root != nullptr) {
            if (key < root->val) {
                if (root->left != nullptr && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != nullptr && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};