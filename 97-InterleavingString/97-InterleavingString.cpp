// Last updated: 10/21/2026, 3:49:03 PM
1class Solution {
2public:
3    bool isInterleave(string s1, string s2, string s3) {
4        int n = s1.size();
5        int m = s2.size();
6        int p = s3.size();
7        if (n + m != p)
8            return false;
9        vector<int> prev(m + 1, 0);
10        vector<int> curr(m + 1, 0);
11        prev[0] = true;
12        for (int j = 1; j <= m; j++) {
13            if (s2[j - 1] == s3[j - 1])
14                prev[j] = prev[j - 1];
15        }
16        for (int i = 1; i <= n; i++) {
17            curr[0] = prev[0] && (s1[i - 1] == s3[i - 1]);
18            for (int j = 1; j <= m; j++) {
19                curr[j] = 0;
20                if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) {
21                    curr[j] = prev[j] || curr[j - 1];
22                } else if (s1[i - 1] == s3[i + j - 1]) {
23                    curr[j] = prev[j];
24                } else if (s2[j - 1] == s3[i + j - 1]) {
25                    curr[j] = curr[j - 1];
26                }
27            }
28            prev = curr;
29        }
30        return prev[m];
31    }
32};