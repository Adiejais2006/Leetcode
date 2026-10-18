// Last updated: 10/18/2026, 2:23:12 PM
1class Solution {
2
3public:
4    int minFallingPathSum(vector<vector<int>>& matrix) {
5        int n = matrix.size();
6        int anss = INT_MAX;
7        vector<vector<int>> dp(n, vector<int>(n, 0));
8        for (int i = 0; i < n; i++) {
9            dp[0][i] = matrix[0][i];
10        }
11        for (int i = 1; i < n; i++) {
12            for (int j = 0; j < n; j++) {
13                int downleft = j > 0 ? dp[i - 1][j - 1] : INT_MAX;
14                int downright = j < n - 1 ? dp[i - 1][j + 1] : INT_MAX;
15                int down = dp[i - 1][j];
16                int best = min(downleft, min(downright, down));
17                if (best == INT_MAX) {
18                    dp[i][j] = INT_MAX;
19                    continue;
20                }
21                dp[i][j] = matrix[i][j] + best;
22            }
23        }
24        for (int i = 0; i < n; i++)
25            anss = min(anss, dp[n - 1][i]);
26        return anss;
27    }
28};