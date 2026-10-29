// Last updated: 10/30/2026, 12:06:50 AM
1class Solution {
2public:
3    int minimumDeleteSum(string s1, string s2) {
4        int n = s1.size();
5        int m = s2.size();
6        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
7        for (int j = m - 1; j >= 0; j--) {
8            dp[n][j] = s2[j] + dp[n][j + 1];
9        }
10        for (int i = n - 1; i >= 0; i--) {
11            dp[i][m] = s1[i] + dp[i + 1][m];
12        }
13        for (int i = n - 1; i >= 0; i--) {
14            for (int j = m - 1; j >= 0; j--) {
15                if (s1[i] == s2[j]) {
16                    dp[i][j] = dp[i + 1][j + 1];
17                } else {
18                    dp[i][j] = min((int)s1[i] + dp[i + 1][j],
19                                   (int)s2[j] + dp[i][j + 1]);
20                }
21            }
22        }
23        return dp[0][0];
24    }
25};
26