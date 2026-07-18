// Last updated: 7/18/2026, 2:04:04 PM

class Solution {int length(TreeNode* root, int &ans) {
        if (root == NULL) return 0;
        int left = length(root->left, ans);
        int right =length(root->right, ans);
        ans = max(ans , left + right) ;
        return 1 + max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        length(root, ans);
        return ans; 
    }
};