// Last updated: 7/18/2026, 2:04:00 PM
class Solution {
public:
    int ans = 0;
    int postorder(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = postorder(root->left);
        int r = postorder(root->right);
        ans += abs(l-r);
        return l + r  + root->val;
    }
    int findTilt(TreeNode* root) {
        postorder(root);
        return ans;
    }
};