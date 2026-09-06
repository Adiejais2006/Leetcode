// Last updated: 9/6/2026, 1:26:28 PM
1class Solution {
2
3public:
4    int numDistinct(string s, string t) {
5        int n = s.size();
6        int m = t.size();
7        if (n < m)
8            return 0;
9        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
10        int MOD = (int)1e9 + 7; // to avoid int overflow
11        for (int i = 0; i <= n; i++) {
12            dp[i][m] = 1;
13        }
14        for (int i = n - 1; i >= 0; i--) {
15            for (int j = m - 1; j >= 0; j--) {
16                int nottake = dp[i + 1][j];
17                int take = 0;
18                if (s[i] == t[j]) {
19                    take = dp[i + 1][j + 1];
20                }
21                dp[i][j] = (take + nottake) % MOD;
22            }
23        }
24        return dp[0][0];
25    }
26};