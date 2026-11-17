// Last updated: 11/17/2026, 1:32:08 PM
1
2class Solution {
3public:
4    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
5        if (root == nullptr)
6            return nullptr;
7        if (root == p || root == q)
8            return root;
9        TreeNode* left = lowestCommonAncestor(root->left, p, q);
10        TreeNode* right = lowestCommonAncestor(root->right, p, q);
11        if (left != NULL && right != NULL)
12            return root;
13        if (left == NULL)
14            return right;
15        else
16            return left;
17    }
18};