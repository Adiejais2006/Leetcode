// Last updated: 10/21/2026, 1:36:54 PM
1class Solution {
2public:
3    int minDistance(string s1, string s2) {
4        int n = s1.size();
5        int m = s2.size();
6        vector<int> prev(m + 1, 0);
7        vector<int> curr(m + 1, 0);
8        for (int j = 0; j <= m; j++) {
9            prev[j] = j;
10        }
11        for (int i = 1; i <= n; i++) {
12            curr[0] = i;
13            for (int j = 1; j <= m; j++) {
14                if (s1[i - 1] == s2[j - 1]) {
15                    curr[j] = prev[j - 1];
16                } else {
17                    int replace = 1 + prev[j - 1];
18                    int del = 1 + prev[j];
19                    int insert = 1 + curr[j - 1];
20                    curr[j] = min({replace, del, insert});
21                }
22            }
23            prev = curr;
24        }
25        return prev[m];
26    }
27};