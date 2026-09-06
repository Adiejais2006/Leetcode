// Last updated: 9/6/2026, 1:29:31 PM
1class Solution {
2
3public:
4    int numDistinct(string s, string t) {
5        int n = s.size();
6        int m = t.size();
7        if (n < m)
8            return 0;
9        vector<int> cur(m + 1, 0);
10        vector<int> prev(m + 1, 0);
11        int MOD = (int)1e9 + 7;
12        prev[m] = 1;
13        cur[m] = 1;
14        for (int i = n - 1; i >= 0; i--) {
15            for (int j = m - 1; j >= 0; j--) {
16                int nottake = prev[j];
17                int take = 0;
18                if (s[i] == t[j]) {
19                    take = prev[j + 1];
20                }
21                cur[j] = (take + nottake) % MOD;
22            }
23            prev = cur;
24        }
25        return cur[0];
26    }
27};