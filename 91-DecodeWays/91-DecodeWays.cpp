// Last updated: 10/22/2026, 4:36:50 PM
1class Solution {
2
3public:
4    int numDecodings(string s) {
5        int n = s.size();
6        vector<int> dp(n + 2, 0);
7        dp[n] = 1;
8        for (int i = n - 1; i >= 0; i--) {
9
10            int one = dp[i + 1];
11            int two = 0;
12
13            if (i + 1 < s.size()) {
14                int a = (s[i] - '0') * 10 + (s[i + 1] - '0');
15                if (a <= 26)
16                    two = dp[i + 2];
17            }
18            dp[i] = one + two;
19            if (s[i] == '0')
20                dp[i] = 0;
21        }
22        return dp[0];
23    }
24};