// Last updated: 9/6/2026, 3:29:44 PM
1class Solution {
2    int height(TreeNode* root) {
3        if (root == NULL)
4            return 0;
5
6        return 1 + max(height(root->left), height(root->right));
7    }
8    bool balance(TreeNode* root) {
9        if (root == NULL)
10            return true;
11        int lh = height(root->left);
12        int rh = height(root->right);
13        if (abs(lh - rh) > 1)
14            return false;
15        return balance(root->left) && balance(root->right);
16    }
17
18public:
19    bool isBalanced(TreeNode* root) { return balance(root); }
20};