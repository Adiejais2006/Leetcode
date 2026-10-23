// Last updated: 10/23/2026, 3:16:54 PM
1class Solution {
2public:
3    int maxScore(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        vector<vector<int>> dp(n, vector<int>(m));
7        int ans = INT_MIN;
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                int mn = INT_MAX;
11                if (i > 0)
12                    mn = min(mn, dp[i - 1][j]);
13                if (j > 0)
14                    mn = min(mn, dp[i][j - 1]);
15                if (i > 0 || j > 0)
16                    ans = max(ans, grid[i][j] - mn);
17                dp[i][j] = min(grid[i][j], mn);
18            }
19        }
20        return ans;
21    }
22};