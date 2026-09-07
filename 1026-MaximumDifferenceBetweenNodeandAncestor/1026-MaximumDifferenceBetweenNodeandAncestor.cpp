// Last updated: 9/7/2026, 10:45:25 PM
1class Solution {
2    void func(TreeNode* root, int& ans, int maxi, int mini) {
3        if (root == NULL)
4            return;
5        ans = max(ans, max(abs(maxi - root->val), abs(mini - root->val)));
6        func(root->left, ans, max(maxi, root->val), min(mini, root->val));
7        func(root->right, ans, max(maxi, root->val), min(mini, root->val));
8    }
9
10public:
11    int maxAncestorDiff(TreeNode* root) {
12        int ans = INT_MIN;
13        func(root, ans,root->val, root->val);
14        return ans;
15    }
16};