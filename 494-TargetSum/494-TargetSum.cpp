// Last updated: 10/24/2026, 4:26:16 PM
1class Solution {
2    int func(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
3        if (target == 0)
4            return 1;
5        if (i < 0)
6            return 0;
7        if (dp[i][target] != -1)
8            return dp[i][target];
9        int nottake = func(i - 1, target, nums, dp);
10        int take = 0;
11        if (target >= nums[i]) {
12            take = func(i - 1, target - nums[i], nums, dp);
13        }
14        return dp[i][target] = take + nottake;
15    }
16
17public:
18    int findTargetSumWays(vector<int>& nums, int target) {
19        int n = nums.size();
20        int sum = 0;
21        for (auto it : nums)
22            sum += it;
23        if ((sum - target) % 2 != 0)
24            return 0;
25        int tar = (sum - target) / 2;
26        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
27        return func(n - 1, tar, nums, dp);
28    }
29};