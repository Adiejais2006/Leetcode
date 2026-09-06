// Last updated: 9/6/2026, 2:48:10 PM
1
2class Solution {
3    void invert(TreeNode* root) {
4        if (root==NULL)return;
5        swap(root->left , root->right);
6        invert(root->left );
7        invert(root->right);
8    }
9
10public:
11    TreeNode* invertTree(TreeNode* root) {
12        invert(root);
13        return root;
14    }
15};