// Last updated: 9/6/2026, 3:33:47 PM
1class Solution {
2
3    int balance(TreeNode* root) {
4        if (root == NULL)
5            return 0;
6        int left = balance(root->left);
7        int right = balance(root->right);
8        if (left == -1 || right == -1)
9            return -1;
10        if (abs(left - right) > 1)
11            return -1;
12        return 1 + max(left, right);
13    }
14
15public:
16    bool isBalanced(TreeNode* root) {
17        int a = balance(root);
18        return a != -1;
19    }
20};