// Last updated: 9/25/2026, 5:29:49 PM
1class Solution {
2public:
3    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
4        int m = obstacleGrid.size();
5        int n = obstacleGrid[0].size();
6        if (obstacleGrid[0][0] == 1)
7            return 0;
8        vector<vector<int>> dp(m, vector<int>(n, 0));
9        dp[0][0] = 1;
10        for (int i = 1; i < m; i++) {
11            if (obstacleGrid[i][0] == 0)
12                dp[i][0] = dp[i - 1][0];
13        }
14        for (int j = 1; j < n; j++) {
15            if (obstacleGrid[0][j] == 0)
16                dp[0][j] = dp[0][j - 1];
17        }
18        for (int i = 1; i < m; i++) {
19            for (int j = 1; j < n; j++) {
20                if (obstacleGrid[i][j] == 1)
21                    continue;
22                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
23            }
24        }
25        return dp[m - 1][n - 1];
26    }
27};