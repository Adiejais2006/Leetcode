// Last updated: 10/22/2026, 9:43:20 PM
1class Solution {
2
3public:
4    bool isMatch(string s, string p) {
5        int n = s.size(), m = p.size();
6        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
7        dp[n][m] = true;
8        for (int i = n; i >= 0; i--) {
9            for (int j = m - 1; j >= 0; j--) {
10                bool firstMatch = i < n && (s[i] == p[j] || p[j] == '.');
11                if (j + 1 < m && p[j + 1] == '*') {
12                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
13                } else if (firstMatch)
14                    dp[i][j] = dp[i + 1][j + 1];
15            }
16        }
17        return dp[0][0];
18    }
19};
20