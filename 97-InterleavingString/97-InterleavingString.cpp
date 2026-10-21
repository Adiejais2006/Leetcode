// Last updated: 10/21/2026, 3:41:02 PM
1class Solution {
2
3public:
4    bool isInterleave(string s1, string s2, string s3) {
5        int n = s1.size();
6        int m = s2.size();
7        int p = s3.size();
8        if (n + m != p)
9            return false;
10        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
11        dp[0][0] = true;
12        for (int j = 1; j <= m; j++) {
13            if (s2[j - 1] == s3[0 + j - 1])
14                dp[0][j] = dp[0][j - 1];
15        }
16        for (int i = 1; i <= n; i++) {
17            if (s1[i - 1] == s3[i + 0 - 1])
18                dp[i][0] = dp[i - 1][0];
19        }
20        for (int i = 1; i <= n; i++) {
21            for (int j = 1; j <= m; j++) {
22                if (i >= 0 && j >= 0 && s1[i - 1] == s3[i + j - 1] &&
23                    s2[j - 1] == s3[i + j - 1]) {
24                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
25                }
26                else if (i >= 0 && s1[i - 1] == s3[i + j - 1])
27                    dp[i][j] = dp[i - 1][j];
28                else if (j >= 0 && s2[j - 1] == s3[i + j - 1])
29                    dp[i][j] = dp[i][j - 1];
30            }
31        }
32        return dp[n][m];
33    }
34};