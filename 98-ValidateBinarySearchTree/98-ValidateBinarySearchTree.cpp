// Last updated: 9/6/2026, 6:55:08 PM
1
2class Solution {
3    bool checker(TreeNode* root, long long low, long long high) {
4        if (root == NULL)
5            return true;
6        if (root->val >= high || root -> val <= low)
7            return false;
8        bool a = checker(root->left, low, root->val);
9        bool b = checker(root->right, root->val, high);
10        return a && b;
11    }
12
13public:
14    bool isValidBST(TreeNode* root) {
15        return checker(root, LLONG_MIN, LLONG_MAX);
16    }
17};