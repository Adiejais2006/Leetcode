// Last updated: 11/10/2026, 7:21:52 PM
1class Solution {
2    int func(int i, vector<int>& nums, vector<int>& dp) {
3        if (i == nums.size() - 1)
4            return 0;
5        if (dp[i+1] != -1)
6            return dp[i+1];
7        int profit = INT_MAX;
8        for (int j = i + 1; j <= i + 3 && j < nums.size(); j++) {
9            profit =
10                min(profit, nums[j] + (j - i) * (j - i) + func(j, nums, dp));
11        }
12        return dp[i+1] = profit;
13    }
14
15public:
16    int climbStairs(int n, vector<int>& costs) {
17        vector<int> dp(n + 3, -1);
18        return func(-1, costs, dp);
19    }
20};