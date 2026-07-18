// Last updated: 7/18/2026, 2:06:41 PM

class Solution {
    bool checker(TreeNode* root,  long long low, long long high) {
        if (root == NULL)
            return true;
        if (root->val <= low || root->val >= high)
            return false;
        return checker(root->left, low, root->val) &&
               checker(root->right, root->val, high);
    }

public:
    bool isValidBST(TreeNode* root) {
        return checker(root, LLONG_MIN, LLONG_MAX);
    }
};