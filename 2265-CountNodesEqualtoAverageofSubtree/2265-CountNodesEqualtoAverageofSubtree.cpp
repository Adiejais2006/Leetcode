// Last updated: 9/10/2026, 8:47:20 PM
1class Solution {
2    int ans = 0;
3    pair<int,int> dfs(TreeNode* node) {
4        if (!node) return {0, 0};
5        auto [ls, lc] = dfs(node->left);
6        auto [rs, rc] = dfs(node->right);
7        int sum = ls + rs + node->val;
8        int cnt = lc + rc + 1;
9        if (sum / cnt == node->val) ans++;
10        return {sum, cnt};
11    }
12public:
13    int averageOfSubtree(TreeNode* root) {
14        dfs(root);
15        return ans;
16    }
17};