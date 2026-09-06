// Last updated: 9/6/2026, 2:59:17 PM
1class Solution {
2    bool func(TreeNode* a, TreeNode* b) {
3        if (a == NULL && b == NULL)
4            return true;
5        if (a == NULL || b == NULL || a->val != b->val)
6            return false;
7        bool movea = func(a->left, b->right);
8        bool moveb = func(a->right, b->left);
9        return movea && moveb;
10    }
11
12public:
13    bool isSymmetric(TreeNode* root) { return func(root, root); }
14};