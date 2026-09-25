// Last updated: 9/25/2026, 5:32:04 PM
1class Solution {
2
3public:
4    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
5        int m = obstacleGrid.size();
6        int n = obstacleGrid[0].size();
7        if (obstacleGrid[0][0] == 1)
8            return 0;
9        vector<vector<int>> dp(m, vector<int>(n, 0));
10        for (int i = 0; i < m; i++) {
11            if (obstacleGrid[i][0] == 1) break;
12                dp[i][0] = 1;
13        }
14        for (int i = 0; i < n; i++) {
15             if (obstacleGrid[0][i] == 1) break;
16                dp[0][i] = 1;
17        }
18        for (int i = 1; i < m; i++) {
19            for (int j = 1; j < n; j++) {
20                if(obstacleGrid[i][j]!=1){
21
22                int up = dp[i - 1][j];
23                int left = dp[i][j - 1];
24                dp[i][j] = up + left;
25                }
26            }
27        }
28        return dp[m - 1][n - 1];
29    }
30};