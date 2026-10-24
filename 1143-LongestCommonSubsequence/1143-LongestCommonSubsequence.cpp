// Last updated: 10/24/2026, 4:17:23 PM
1class Solution {
2
3public:
4    int longestCommonSubsequence(string text1, string text2) {
5        int n = text1.size();
6        int m = text2.size();
7        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
8        for (int i = 1; i <= n; i++) {
9            for (int j = 1; j <= m; j++) {
10                if (text1[i-1] == text2[j-1]) {
11                    dp[i][j] = 1 + dp[i - 1][j - 1];
12                } else {
13                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
14                }
15            }
16        }
17         return dp[n][m];
18    }
19};