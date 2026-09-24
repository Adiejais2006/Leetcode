// Last updated: 9/24/2026, 12:06:40 PM
1class Solution {
2
3public:
4    int fib(int n) {
5        if(n==0)return 0;
6        vector<int> dp(n + 1, 0);
7        dp[0] = 0;
8        dp[1] = 1;
9        for (int i = 2; i <= n; i++) {
10            dp[i] = dp[i - 1]+ dp[i - 2];
11        }
12        return dp[n];
13    }
14};