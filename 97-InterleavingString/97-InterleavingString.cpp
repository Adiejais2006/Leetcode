// Last updated: 10/21/2026, 3:28:05 PM
1class Solution {
2    int func(int i, int j, string& s1, string& s2, string& s3,
3             vector<vector<int>>& dp) {
4        if (dp[i][j] != -1)
5            return dp[i][j];
6        if (i == 0 && j == 0)
7            return dp[i][j] = true;
8        if (i == 0) {
9            if (s2[j - 1] == s3[i + j - 1])
10                return dp[i][j] = func(i, j - 1, s1, s2, s3, dp);
11            return dp[i][j] = false;
12        }
13        if (j == 0) {
14            if (s1[i - 1] == s3[i + j - 1])
15                return dp[i][j] = func(i - 1, j, s1, s2, s3, dp);
16            return dp[i][j] = false;
17        }
18
19        if (i >= 0 && j >= 0 && s1[i - 1] == s3[i + j - 1] &&
20            s2[j - 1] == s3[i + j - 1]) {
21            return dp[i][j] = func(i - 1, j, s1, s2, s3, dp) ||
22                              func(i, j - 1, s1, s2, s3, dp);
23        }
24        if (i >= 0 && s1[i - 1] == s3[i + j - 1])
25            return dp[i][j] = func(i - 1, j, s1, s2, s3, dp);
26        if (j >= 0 && s2[j - 1] == s3[i + j - 1])
27            return dp[i][j] = func(i, j - 1, s1, s2, s3, dp);
28        return dp[i][j] = false;
29    }
30
31public:
32    bool isInterleave(string s1, string s2, string s3) {
33        int n = s1.size();
34        int m = s2.size();
35        int p = s3.size();
36        if (n + m != p)
37            return false;
38        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
39        return func(n, m, s1, s2, s3, dp);
40    }
41};