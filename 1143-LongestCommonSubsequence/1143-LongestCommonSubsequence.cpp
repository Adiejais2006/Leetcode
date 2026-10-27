// Last updated: 10/27/2026, 3:20:20 PM
1class Solution {
2    int rec(int i, int j, string &s1, string &s2) {
3        if (i == s1.size() || j == s2.size())
4            return 0;
5        if (s1[i] == s2[j]) {
6            return 1 + rec(i + 1, j + 1, s1, s2);
7        } else {
8            return max(rec(i + 1, j, s1, s2), rec(i, j + 1, s1, s2));
9        }
10    }
11    int memo(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
12        if (i == s1.size() || j == s2.size())
13            return 0;
14        if (dp[i][j] != -1)
15            return dp[i][j];
16        if (s1[i] == s2[j]) {
17            return  dp[i][j] = 1 + memo(i + 1, j + 1, s1, s2, dp);
18        } else {
19            return dp[i][j] = max(memo(i + 1, j, s1, s2, dp),
20                                  memo(i, j + 1, s1, s2, dp));
21        }
22    }
23
24public:
25    int longestCommonSubsequence(string text1, string text2) {
26        int n = text1.size();
27        int m = text2.size();
28        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
29        return memo(0, 0, text1, text2, dp);
30    }
31};