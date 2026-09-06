// Last updated: 9/6/2026, 10:34:22 PM
1
2class Solution {
3
4    TreeNode* insert(TreeNode* root, int val) {
5        if (root == NULL)
6           return new TreeNode(val);
7        if (root->val > val) {
8            root->left = insert(root->left, val);
9        }
10        if (root->val < val) {
11            root->right = insert(root->right, val);
12        }
13        return root;
14    }
15
16public:
17    TreeNode* insertIntoBST(TreeNode* root, int val) {
18        return insert(root, val);
19    }
20};