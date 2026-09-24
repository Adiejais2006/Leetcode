// Last updated: 9/24/2026, 1:10:36 PM
1class Solution {
2    int func(int ind, vector<int>& cost,vector<int>& dp) {
3        if (ind < 0)
4            return 0;
5        if (ind == 0 || ind == 1) {
6            return cost[ind];
7        }
8        if(dp[ind]!=-1) return dp[ind];
9        int step1 = cost[ind] + func(ind - 1, cost,dp);
10        int step2 = cost[ind] + func(ind - 2, cost,dp);
11        return dp[ind] = min(step1, step2);
12    }
13
14public:
15    int minCostClimbingStairs(vector<int>& cost) {
16        int n = cost.size();
17        vector<int> dp(n+1,-1);
18        return min(func(n - 2, cost,dp), func(n - 1, cost,dp));
19    }
20};