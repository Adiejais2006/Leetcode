// Last updated: 9/8/2026, 9:56:38 PM
1class Solution {
2    pair<int, int> func(TreeNode* root) {
3        if (root == NULL)
4            return {0, 0};
5        auto left = func(root->left);
6        auto right = func(root->right);
7        int rob = root->val + left.second + right.second;
8        int notrob =
9            max(left.first, left.second) + max(right.first, right.second);
10        return {rob, notrob};
11    }
12
13public:
14    int rob(TreeNode* root) {
15        auto ans = func(root);
16        return max(ans.first, ans.second);
17    }
18};