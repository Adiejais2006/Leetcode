// Last updated: 9/24/2026, 1:16:34 PM
1class Solution {
2
3public:
4    int minCostClimbingStairs(vector<int>& cost) {
5        int n = cost.size();
6        vector<int> dp(n + 1, -1);
7        dp[0] = cost[0];
8        dp[1] = cost[1];
9        for (int ind = 2; ind < n; ind++) {
10            int step1 = cost[ind] + dp[ind - 1];
11            int step2 = cost[ind] + dp[ind - 2];
12            dp[ind] = min(step1, step2);
13        }
14        return min(dp[n - 2], dp[n - 1]);
15    }
16};