// Last updated: 9/6/2026, 10:29:58 PM
1
2class Solution {
3    TreeNode* mini(TreeNode* root) {
4        if (root->left == NULL)
5            return root;
6        return mini(root->left);
7    }
8    TreeNode* func(TreeNode* root, int key) {
9        if (root == NULL)
10            return NULL;
11        if (root->val > key) {
12            root->left = func(root->left, key);
13        } else if (root->val < key) {
14            root->right = func(root->right, key);
15        } else {
16            if (root->left == NULL && root->right == NULL) {
17                return NULL;
18            }
19            if (root->left == NULL) {
20                return root->right;
21            }
22            if (root->right == NULL) {
23                return root->left;
24            }
25            TreeNode* node = mini(root->right);
26            root->val = node->val;
27            root->right = func(root->right, node->val);
28        }
29        return root;
30    }
31
32public:
33    TreeNode* deleteNode(TreeNode* root, int key) { return func(root, key); }
34};