// Last updated: 10/22/2026, 9:36:22 PM
1class Solution {
2    bool func(int i, int j, string& s, string& p,
3              vector<vector<int>>& dp) {
4        if (j == p.size())
5            return i == s.size();
6        if (dp[i][j] != -1)
7            return dp[i][j];
8        bool firstMatch = i < s.size() &&
9                          (s[i] == p[j] || p[j] == '.');
10        if (j + 1 < p.size() && p[j + 1] == '*') {
11            return dp[i][j] =
12                func(i, j + 2, s, p, dp) ||
13                (firstMatch && func(i + 1, j, s, p, dp));
14        }
15        if (firstMatch)
16            return dp[i][j] = func(i + 1, j + 1, s, p, dp);
17        return dp[i][j] = false;
18    }
19public:
20    bool isMatch(string s, string p) {
21        int n = s.size(), m = p.size();
22        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
23        return func(0, 0, s, p, dp);
24    }
25};
26
27