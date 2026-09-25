// Last updated: 9/25/2026, 5:29:19 PM
1class Solution {
2    int func(int i, int j, vector<vector<int>>& dp,
3             vector<vector<int>>& obstacleGrid) {
4        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
5            return 0;
6        if (i == 0 && j == 0)
7            return 1;
8        if (dp[i][j] != -1)
9            return dp[i][j];
10        int up = func(i - 1, j, dp, obstacleGrid);
11        int left = func(i, j - 1, dp, obstacleGrid);
12        return dp[i][j] = up + left;
13    }
14
15public:
16    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
17        int m = obstacleGrid.size();
18        int n = obstacleGrid[0].size();
19
20        vector<vector<int>> dp(m, vector<int>(n, -1));
21        return func(m - 1, n - 1, dp, obstacleGrid);
22    }
23};