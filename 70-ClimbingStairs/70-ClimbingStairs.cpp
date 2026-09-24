// Last updated: 9/24/2026, 12:15:43 PM
1class Solution {
2    int func(int n, vector<int>& dp) {
3        if (n < 0)
4            return 0;
5        if (n == 0) {
6            return 1;
7        }
8        if(dp[n]!=-1)return dp[n];
9        int way1 = func(n - 1, dp);
10        int way2 = func(n - 2, dp);
11        return dp[n] =way1 + way2;
12    }
13
14public:
15    int climbStairs(int n) {
16        vector<int> dp(n+1, -1);
17        return func(n, dp);
18    }
19};