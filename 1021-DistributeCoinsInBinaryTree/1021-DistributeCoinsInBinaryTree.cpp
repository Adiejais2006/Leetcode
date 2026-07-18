// Last updated: 7/18/2026, 2:02:49 PM

class Solution {
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans += abs(left) + abs(right);
        return root->val +left + right - 1;
    }

public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};