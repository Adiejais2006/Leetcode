// Last updated: 10/27/2026, 3:23:33 PM
1class Solution {
2    int rec(int i, int j, string& s1, string& s2) {
3        if (i == s1.size() || j == s2.size())
4            return 0;
5        if (s1[i] == s2[j]) {
6            return 1 + rec(i + 1, j + 1, s1, s2);
7        } else {
8            return max(rec(i + 1, j, s1, s2), rec(i, j + 1, s1, s2));
9        }
10    }
11    int memo(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
12        if (i == s1.size() || j == s2.size())
13            return 0;
14        if (dp[i][j] != -1)
15            return dp[i][j];
16        if (s1[i] == s2[j]) {
17            return dp[i][j] = 1 + memo(i + 1, j + 1, s1, s2, dp);
18        } else {
19            return dp[i][j] = max(memo(i + 1, j, s1, s2, dp),
20                                  memo(i, j + 1, s1, s2, dp));
21        }
22    }
23
24    int tab(string& s1, string& s2) {
25        int n = s1.size();
26        int m = s2.size();
27        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
28        for (int i = n - 1; i >= 0; i--) {
29            for (int j = m - 1; j >= 0; j--) {
30                if (s1[i] == s2[j]) {
31                    dp[i][j] = 1 + dp[i + 1][j + 1];
32                } else {
33                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
34                }
35            }
36        }
37        return dp[0][0];
38    }
39
40public:
41    int longestCommonSubsequence(string text1, string text2) {
42        int n = text1.size();
43        int m = text2.size();
44        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
45        return tab(text1, text2);
46    }
47};