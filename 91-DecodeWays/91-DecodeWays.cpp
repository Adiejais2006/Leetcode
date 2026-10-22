// Last updated: 10/22/2026, 4:37:34 PM
1class Solution {
2public:
3    int numDecodings(string s) {
4        int n = s.size();
5        vector<int> dp(n + 2, 0);
6        dp[n] = 1;
7        for (int i = n - 1; i >= 0; i--) {
8            if (s[i] == '0') {
9                continue;
10            }
11            int one = dp[i + 1];
12            int two = 0;
13
14            if (i + 1 < n) {
15                int a = (s[i] - '0') * 10 + (s[i + 1] - '0');
16
17                if (a >= 10 && a <= 26) {
18                    two = dp[i + 2];
19                }
20            }
21
22            dp[i] = one + two;
23        }
24
25        return dp[0];
26    }
27};