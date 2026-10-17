// Last updated: 10/17/2026, 6:13:22 PM
1class Solution {
2    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
3        if (i < 0 || j < 0)
4            return INT_MAX;
5        if (i == 0 && j == 0)
6            return grid[i][j];
7        if (dp[i][j] != -1)
8            return dp[i][j];
9
10        int up = func(i - 1, j, grid, dp);
11        int left = func(i, j - 1, grid, dp);
12        int best = min(left, up);
13        if (best == INT_MAX)
14            return INT_MAX;
15        return dp[i][j] = grid[i][j] + best;
16    }
17
18public:
19    int minPathSum(vector<vector<int>>& grid) {
20        int n = grid.size() ;int m = grid[0].size();
21        vector<vector<int>> dp(n, vector<int>(m, -1));
22        return func(n - 1, m - 1, grid, dp);
23    }
24};