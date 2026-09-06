// Last updated: 9/6/2026, 8:45:28 PM
1class Solution {
2public:
3    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
4        if (root == NULL)
5            return NULL;
6        if (root == p || root == q)
7            return root;
8        TreeNode* left = lowestCommonAncestor(root->left, p, q);
9        TreeNode* right = lowestCommonAncestor(root->right, p, q);
10        if (left != NULL && right != NULL)
11            return root;
12        if (left == NULL)
13            return right;
14        else
15            return left;
16        if (right == NULL)
17            return left;
18        else
19            return right;
20    }
21};