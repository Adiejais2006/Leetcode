// Last updated: 7/18/2026, 2:06:26 PM
class Solution {
    bool leaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }
    bool dfs(TreeNode* root, int target) {
        if (root == NULL)
            return false;
        if (leaf(root))
            return target == root->val;

        return dfs(root->left, target - root->val) ||
               dfs(root->right, target - root->val);
    }

public:
    bool hasPathSum(TreeNode* root, int target) { return dfs(root, target); }
};