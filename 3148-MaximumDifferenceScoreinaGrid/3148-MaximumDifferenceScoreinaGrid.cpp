// Last updated: 10/23/2026, 3:16:20 PM
1class Solution {
2    int func(int i, int j, vector<vector<int>>& grid,
3             vector<vector<int>>& dp) {
4        if (i == 0 && j == 0)
5            return dp[0][0] = grid[0][0];
6        if (dp[i][j] != -1)
7            return dp[i][j];
8        int mn = INT_MAX;
9        if (i > 0)
10            mn = min(mn, func(i - 1, j, grid, dp));
11        if (j > 0)
12            mn = min(mn, func(i, j - 1, grid, dp));
13        return dp[i][j] = min(grid[i][j], mn);
14    }
15public:
16    int maxScore(vector<vector<int>>& grid) {
17        int n = grid.size();
18        int m = grid[0].size();
19        int ans = INT_MIN;
20        vector<vector<int>> dp(n, vector<int>(m, -1));
21        for (int i = 0; i < n; i++) {
22            for (int j = 0; j < m; j++) {
23                int mn = INT_MAX;
24                if (i > 0)
25                    mn = min(mn, func(i - 1, j, grid, dp));
26                if (j > 0)
27                    mn = min(mn, func(i, j - 1, grid, dp));
28                if (i > 0 || j > 0)
29                    ans = max(ans, grid[i][j] - mn);
30            }
31        }
32        return ans;
33    }
34};