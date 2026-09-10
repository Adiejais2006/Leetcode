// Last updated: 9/11/2026, 1:54:57 AM
1class Solution {
2    int moves = 0;
3    int func(TreeNode* root) {
4        if (root == NULL)
5            return 0;
6        int left = func(root->left);
7        int right = func(root->right);
8        moves += abs(left) + abs(right);
9        return root->val + left + right - 1;
10    }
11
12public:
13    int distributeCoins(TreeNode* root) {
14        func(root);
15        return moves;
16    }
17};