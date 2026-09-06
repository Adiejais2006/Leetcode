// Last updated: 9/6/2026, 9:05:05 PM
1
2class Solution {
3    TreeNode* find(TreeNode* root, int val) {
4        if (root == NULL)
5            return root;
6        if (root->val == val)
7            return root;
8        if (root->val > val) {
9            return find(root->left, val);
10        }
11        if (root->val < val) {
12            return find(root->right, val);
13        }
14        return root;
15    }
16
17public:
18    TreeNode* searchBST(TreeNode* root, int val) { return find(root, val); }
19};