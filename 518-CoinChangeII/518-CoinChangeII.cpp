// Last updated: 10/19/2026, 3:27:08 PM
1class Solution {
2    int func(int i, int amount, vector<int>& nums, vector<vector<int>>& dp) {
3        if (amount == 0)
4            return 1;
5        if (i == 0) {
6            if (amount % nums[i] == 0)
7                return 1;
8            else
9                return 0;
10        }
11        if (dp[i][amount] != -1)
12            return dp[i][amount];
13        int nottake = func(i - 1, amount, nums, dp);
14        int take = 0;
15        if (amount >= nums[i]) {
16            take = func(i, amount - nums[i], nums, dp);
17        }
18        return dp[i][amount] = take + nottake;
19    }
20
21public:
22    int change(int amount, vector<int>& coins) {
23        int n = coins.size();
24        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
25        return func(n - 1, amount, coins, dp);
26    }
27};