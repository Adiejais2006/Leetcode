// Last updated: 9/9/2026, 12:00:16 AM
1class Solution {
2    TreeNode* build(int maxi, int mini, int& i, vector<int>& preorder) {
3        if (i == preorder.size())
4            return NULL;
5        if (preorder[i] < mini || preorder[i] > maxi)
6            return NULL;
7        TreeNode* root = new TreeNode(preorder[i]);
8        i++;
9        root->left = build(root->val, mini, i, preorder);
10        root->right = build(maxi, root->val, i, preorder);
11        return root;
12    }
13
14public:
15    TreeNode* bstFromPreorder(vector<int>& preorder) {
16        int i = 0;
17        return build(INT_MAX, INT_MIN, i, preorder);
18    }
19};