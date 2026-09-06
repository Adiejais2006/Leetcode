// Last updated: 9/6/2026, 12:56:12 PM
1class Solution {
2    int func(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
3        if (j == t.size())
4            return 1;
5        if (i == s.size())
6            return 0;
7        if (dp[i][j] != -1)
8            return dp[i][j];
9        int nottake = func(i + 1, j, s, t, dp);
10        int take = 0;
11        if (s[i] == t[j]) {
12            take = func(i + 1, j + 1, s, t, dp);
13        }
14        return dp[i][j] = take + nottake;
15    }
16
17public:
18    int numDistinct(string s, string t) {
19        int n = s.size();
20        int m = t.size();
21        vector<vector<int>> dp(n, vector<int>(m, -1));
22        return func(0, 0, s, t, dp);
23    }
24};