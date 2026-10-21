// Last updated: 10/21/2026, 11:40:57 PM
1class Solution {
2    int longestCommonSubsequence(string s1, string s2) {
3        int n = s1.size();
4        int m = s2.size();
5        vector<int> prev(m + 1, 0);
6        vector<int> curr(m + 1, 0);
7        for (int i = 1; i <= n; i++) {
8            for (int j = 1; j <= m; j++) {
9                if (s1[i - 1] == s2[j - 1]) {
10                    curr[j] = 1 + prev[j - 1];
11                } else {
12                    curr[j] = max(prev[j], curr[j - 1]);
13                }
14            }
15            prev = curr;
16        }
17        return prev[m];
18    }
19
20public:
21    int longestPalindromeSubseq(string s) {
22        string orig = s;
23        reverse(orig.begin() , orig.end());
24        int a = longestCommonSubsequence(s,orig);
25        return a;
26    }
27};