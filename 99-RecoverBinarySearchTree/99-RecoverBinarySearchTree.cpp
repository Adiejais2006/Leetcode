// Last updated: 9/13/2026, 4:41:22 PM
1class Solution {
2    TreeNode* prev = nullptr;
3    TreeNode* first = nullptr;
4    TreeNode* second = nullptr;
5    void inorder(TreeNode* root) {
6        if (!root)
7            return;
8        inorder(root->left);
9        if (prev && prev->val > root->val) {
10            if (!first)
11                first = prev;
12            second = root;
13        }
14        prev = root;
15        inorder(root->right);
16    }
17
18public:
19    void recoverTree(TreeNode* root) {
20        inorder(root);
21        swap(first->val, second->val);
22    }
23};