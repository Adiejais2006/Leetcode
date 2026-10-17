// Last updated: 10/17/2026, 6:22:29 PM
1class Solution {
2public:
3    int minPathSum(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
7        dp[0][0] = grid[0][0];
8        for (int i = 1; i < n; i++) {
9            dp[i][0] = grid[i][0] + dp[i - 1][0];
10        }
11        for (int j = 1; j < m; j++) {
12            dp[0][j] = grid[0][j] + dp[0][j - 1];
13        }
14        for (int i = 1; i < n; i++) {
15            for (int j = 1; j < m; j++) {
16                int up = dp[i - 1][j];
17                int left = dp[i][j - 1];
18                int best = min(left, up);
19                dp[i][j] = grid[i][j] + best;
20            }
21        }
22        return dp[n - 1][m - 1];
23    }
24};