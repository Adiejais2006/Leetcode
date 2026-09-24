// Last updated: 9/24/2026, 12:04:00 PM
1class Solution {
2    int func(int n, vector<int>& dp) {
3        if (n == 0)
4            return 0;
5        if (n == 1)
6            return 1;
7        if (dp[n] != -1)
8            return dp[n];
9        return dp[n] = func(n - 1, dp) + func(n - 2, dp);
10    }
11
12public:
13    int fib(int n) {
14        vector<int> dp(n + 1, -1);
15        return func(n, dp);
16    }
17};