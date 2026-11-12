// Last updated: 11/12/2026, 6:34:52 PM
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
13                int topleft = j - 1 >= 0 ? dp[i - 1][j - 1] : INT_MAX;
14                int topright = j + 1 < n ? dp[i - 1][j + 1] : INT_MAX;
15                dp[i][j] = matrix[i][j] + min(top, min(topleft, topright));
16            }
17        }
18        int ans = INT_MAX;
19        for (int i = 0; i < n; i++) {
20            ans = min(ans, dp[n - 1][i]);
21        }
22        return ans;
23    }
24};