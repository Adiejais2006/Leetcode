// Last updated: 10/21/2026, 10:36:27 PM
1
2class Solution {
3    pair<int, int> func(TreeNode* root) {
4        if (!root)
5            return {0, 0};
6        auto left = func(root->left);
7        auto right = func(root->right);
8        auto skip =
9            max(left.first, left.second) +  max(right.first, right.second);
10        ;
11        auto take = root->val + left.second + right.second;
12        ;
13        return {take, skip};
14    }
15
16public:
17    int rob(TreeNode* root) {
18        
19        auto a = func(root);
20        return max(a.first, a.second);
21    }
22};