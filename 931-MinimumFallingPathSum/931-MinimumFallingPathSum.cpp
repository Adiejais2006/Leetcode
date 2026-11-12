// Last updated: 11/12/2026, 6:37:00 PM
1class Solution {
2
3public:
4    int minFallingPathSum(vector<vector<int>>& matrix) {
5        int n = matrix.size();
6        vector<vector<int>> dp(n, vector<int>(n, 0));
7        for (int j = 0; j < n; j++) {
8            dp[0][j] = matrix[0][j];
9        }
10        for (int i = 1; i < n; i++) {
11            for (int j = 0; j < n; j++) {
12                int top = dp[i - 1][j];
13                // if (j < 0 || j >= n)
14                //     return INT_MAX;
15                int topleft = j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX;
16                int topright = j + 1 < n ? dp[i - 1][j + 1] : INT_MAX;
17                dp[i][j] = matrix[i][j] + min(top, min(topleft, topright));
18            }
19        }
20        int ans = INT_MAX;
21        for (int i = 0; i < n; i++) {
22            ans = min(ans, dp[n - 1][i]);
23        }
24        return ans;
25    }
26};