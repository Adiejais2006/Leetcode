// Last updated: 10/18/2026, 2:53:45 PM
1class Solution {
2public:
3    int longestCommonSubsequence(string s1, string s2) {
4        int n = s1.size();
5        int m = s2.size();
6        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
7        for (int i = 1; i <= n; i++) {
8            for (int j = 1; j <= m; j++) {
9                if (s1[i - 1] == s2[j - 1]) {
10                    dp[i][j] = 1 + dp[i - 1][j - 1];
11                } else {
12                    int skipleft = dp[i - 1][j];
13                    int skipright = dp[i][j - 1];
14                    dp[i][j] = max(skipleft, skipright);
15                }
16            }
17        }
18        return dp[n][m];
19    }
20};