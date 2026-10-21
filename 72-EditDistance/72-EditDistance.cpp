// Last updated: 10/21/2026, 1:30:18 PM
1class Solution {
2public:
3    int minDistance(string s1, string s2) {
4        int n = s1.size();
5        int m = s2.size();
6        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
7        for (int i = 0; i <= n; i++)
8            dp[i][0] = i;
9        for (int j = 0; j <= m; j++)
10            dp[0][j] = j;
11        for (int i = 1; i <= n; i++) {
12            for (int j = 1; j <= m; j++) {
13                if (s1[i - 1] == s2[j - 1]) {
14                    dp[i][j] = dp[i - 1][j - 1];
15                } else {
16                    int replace = 1 + dp[i - 1][j - 1];
17                    int del = 1 + dp[i - 1][j];
18                    int insert = 1 + dp[i][j - 1];
19
20                    dp[i][j] = min({replace, del, insert});
21                }
22            }
23        }
24        return dp[n][m];
25    }
26};