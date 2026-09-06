// Last updated: 9/6/2026, 5:06:08 PM
1class Solution {
2public:
3    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
4        if (root == NULL)
5            return root;
6        if (root == p || root == q)
7            return root;
8        TreeNode* left = lowestCommonAncestor(root->left, p, q);
9        TreeNode* right = lowestCommonAncestor(root->right, p, q);
10        if (left != NULL && right != NULL)
11            return root;
12        else {
13            return (left != NULL) ? left : right;
14        }
15    }
16};