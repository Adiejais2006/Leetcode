// Last updated: 9/25/2026, 5:01:23 PM
1class Solution {
2    int func(int i, int j, vector<vector<int>>& dp) {
3        if (i == 0 && j == 0)
4            return 1;
5        if (i < 0 || j < 0)
6            return 0;
7        if (dp[i][j] != -1)
8            return dp[i][j];
9        int up = func(i - 1, j, dp);
10        int left = func(i, j - 1, dp);
11        return dp[i][j] = up + left;
12    }
13
14public:
15    int uniquePaths(int m, int n) {
16        vector<vector<int>> dp(m, vector<int>(n, -1));
17        return func(m - 1, n - 1, dp);
18    }
19};