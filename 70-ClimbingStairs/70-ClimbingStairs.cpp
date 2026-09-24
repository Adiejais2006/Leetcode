// Last updated: 9/24/2026, 12:20:20 PM
1class Solution {
2public:
3    int climbStairs(int n) {
4        vector<int> dp(n + 1, 0);
5        dp[0] = 1;
6        dp[1] = 1 ;
7        for (int i = 2; i <= n; i++) {
8            int way1 =dp[i - 1];
9            int way2 = dp[i - 2];
10           dp[i] = way1 + way2;
11        }
12        return dp[n];
13    }
14};