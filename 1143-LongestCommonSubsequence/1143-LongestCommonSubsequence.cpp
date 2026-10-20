// Last updated: 10/21/2026, 1:14:17 AM
1class Solution {
2
3public:
4    int longestCommonSubsequence(string s1, string s2) {
5        int n = s1.size();
6        int m = s2.size();
7        vector<int>prev(m + 1, 0);
8        vector<int>curr(m + 1, 0);
9        for (int i = 1; i <= n; i++) {
10            for (int j = 1; j <= m; j++) {
11                if (s1[i - 1] == s2[j - 1]) {
12                   curr[j] = 1 + prev[j - 1];
13                } else {
14                   curr[j] = max(prev[j], curr[j - 1]);
15                }
16            }
17            prev = curr;
18        }
19        return prev[m];
20    }
21};