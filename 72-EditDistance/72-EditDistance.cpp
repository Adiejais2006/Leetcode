// Last updated: 11/2/2026, 4:22:09 PM
1class Solution {
2public:
3    int minDistance(string word1, string word2) {
4        int n = word1.size();
5        int m = word2.size();
6        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
7        for (int i = 0; i <= m; i++) {
8            dp[n][i] = word2.size() - i;
9        }
10        for (int i = 0; i <= n; i++) {
11            dp[i][m] = word1.size() - i;
12        }
13        for (int i = n - 1; i >= 0; i--) {
14            for (int j = m - 1; j >= 0; j--) {
15                if (word1[i] == word2[j])
16                    dp[i][j] = dp[i + 1][j + 1];
17                else {
18                    int replace = 1 + dp[i + 1][j + 1];
19                    int deleted = 1 + dp[i + 1][j];
20                    int insert = 1 + dp[i][j + 1];
21                    dp[i][j] = min(replace, min(deleted, insert));
22                }
23            }
24        }
25        return dp[0][0];
26    }
27};
28