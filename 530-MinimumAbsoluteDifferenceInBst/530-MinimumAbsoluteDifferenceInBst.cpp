// Last updated: 7/18/2026, 2:04:07 PM

class Solution {
    int ans = INT_MAX;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        if(prev)ans = min(ans, abs(prev->val - root->val));
        prev = root;
        inorder(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};