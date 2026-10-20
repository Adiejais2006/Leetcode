// Last updated: 10/20/2026, 6:37:47 PM
1class Solution {
2public:
3    int numDistinct(string s, string t) {
4        int n = s.size();
5        int m = t.size();
6        vector<vector<unsigned long long>> dp(
7            n + 1, vector<unsigned long long>(m + 1, 0));
8        for (int i = 0; i <= n; i++)
9            dp[i][0] = 1;
10        for (int i = 1; i <= n; i++) {
11            for (int j = 1; j <= m; j++) {
12                unsigned long long pick = 0;
13                if (s[i - 1] == t[j - 1])
14                    pick = dp[i - 1][j - 1];
15                unsigned long long notpick = dp[i - 1][j];
16                dp[i][j] = pick + notpick;
17            }
18        }
19        return dp[n][m];
20    }
21};