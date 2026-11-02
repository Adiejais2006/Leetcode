// Last updated: 11/2/2026, 4:12:40 PM
1class Solution {
2    int func(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
3        if (i == s1.size())
4            return s2.size() - j;
5        if (j == s2.size())
6            return s1.size() - i;
7        if (dp[i][j] != -1)
8            return dp[i][j];
9
10        if (s1[i] == s2[j])
11            return dp[i][j] = func(i + 1, j + 1, s1, s2, dp);
12        else {
13            int replace = 1 + func(i + 1, j + 1, s1, s2, dp);
14            int deleted = 1 + func(i + 1, j, s1, s2, dp);
15            int insert = 1 + func(i, j + 1, s1, s2, dp);
16            return dp[i][j] = min(replace, min(deleted, insert));
17        }
18    }
19
20public:
21    int minDistance(string word1, string word2) {
22        int n = word1.size();
23        int m = word2.size();
24        vector<vector<int>> dp(n, vector<int>(m, -1));
25        return func(0, 0, word1, word2, dp);
26    }
27};
28