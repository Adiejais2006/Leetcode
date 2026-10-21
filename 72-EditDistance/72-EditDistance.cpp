// Last updated: 10/21/2026, 1:22:32 PM
1class Solution {
2    int func(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
3        if (i < 0 && j >= 0)
4            return j + 1;
5        if (j < 0 && i >= 0) {
6            return i + 1;
7        }
8        if (i < 0 || j < 0)
9            return 0;
10        if (dp[i][j] != -1)
11            return dp[i][j];
12        if (s1[i] == s2[j]) {
13            return dp[i][j] = func(i - 1, j - 1, s1, s2, dp);
14        }
15        int replace = 1 + func(i - 1, j - 1, s1, s2, dp);
16        int del = 1 + func(i - 1, j, s1, s2, dp);
17        int insert = 1 + func(i, j - 1, s1, s2, dp);
18        return dp[i][j] = min(replace, min(del, insert));
19    }
20
21public:
22    int minDistance(string word1, string word2) {
23        int n = word1.size();
24        int m = word2.size();
25        vector<vector<int>> dp(n, vector<int>(m, -1));
26        return func(n - 1, m - 1, word1, word2, dp);
27    }
28};