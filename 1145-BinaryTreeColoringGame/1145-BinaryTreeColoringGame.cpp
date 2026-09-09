// Last updated: 9/9/2026, 2:42:53 PM
1class Solution {
2    TreeNode* find(TreeNode* root, int x) {
3        if (!root)
4            return nullptr;
5        if (root->val == x)
6            return root;
7        TreeNode* left = find(root->left, x);
8        if (left)
9            return left;
10        return find(root->right, x);
11    }
12    int cnt(TreeNode* node) {
13        if (!node)
14            return 0;
15        return 1 + cnt(node->left) + cnt(node->right);
16    }
17
18public:
19    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
20        TreeNode* red = find(root, x);
21        int leftchild = cnt(red->left);
22        int rightchild = cnt(red->right);
23        int parentNodes = n - leftchild - rightchild - 1;
24        int maxu = max(parentNodes, max(leftchild, rightchild));
25        return maxu > n / 2;
26    }
27};