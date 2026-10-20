// Last updated: 10/20/2026, 5:30:07 PM
1class Solution {
2    int func(int i, int j, string& s, string& t,
3             vector<vector<int>>& dp) {
4        if (j < 0)
5            return 1;
6        if (i < 0)
7            return 0;
8        if (dp[i][j] != -1)
9            return dp[i][j];
10        int pick = 0;
11        if (s[i] == t[j])
12            pick = func(i - 1, j - 1, s, t, dp);
13        int notpick = func(i - 1, j, s, t, dp);
14        return dp[i][j] = pick + notpick;
15    }
16
17public:
18    int numDistinct(string s, string t) {
19        int n = s.size();
20        int m = t.size();
21        vector<vector<int>> dp(n, vector<int>(m, -1));
22        return func(n - 1, m - 1, s, t, dp);
23    }
24};