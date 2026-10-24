// Last updated: 10/24/2026, 3:00:55 PM
1
2class Solution {
3public:
4    int integerBreak(int n) {
5        vector<int> dp(n + 1, 0);
6        dp[1] = 1;
7        for (int i = 2; i <= n; i++) {
8            for (int j = 1; j < i; j++) {
9                dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
10            }
11        }
12        return dp[n];
13    }
14};
15