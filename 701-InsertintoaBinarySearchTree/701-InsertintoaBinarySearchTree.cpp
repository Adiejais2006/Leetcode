// Last updated: 9/6/2026, 9:13:37 PM
1
2class Solution {
3
4    TreeNode* insert(TreeNode* root, int val) {
5        if (root == NULL) {
6            return new TreeNode(val);
7        }
8        if (root->val > val) {
9            root->left = insert(root->left, val);
10        }
11        if (root->val < val) {
12            root->right = insert(root->right, val);
13        }
14        return root;
15    }
16
17public:
18    TreeNode* insertIntoBST(TreeNode* root, int val) {
19        return insert(root, val);
20    }
21};