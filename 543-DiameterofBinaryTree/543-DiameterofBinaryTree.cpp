// Last updated: 9/6/2026, 3:18:12 PM
1class Solution {
2    int func(TreeNode* root, int& ans) {
3        if (root == NULL)
4            return 0;
5        int left = func(root->left, ans);
6        int right = func(root->right, ans);
7        ans = max(ans, (left + right));
8        return 1 + max(left, right);
9    }
10public:
11    int diameterOfBinaryTree(TreeNode* root) {
12        int ans = INT_MIN;
13        func(root, ans);
14        return ans;
15    }
16};