// Last updated: 10/19/2026, 1:14:11 PM
1class Solution {
2    int func(int i, int target, vector<int>& nums,
3             vector<vector<int>>& dp) {
4        if (target == 0)
5            return 0;
6        if (i < 0)
7            return 0;
8        if (dp[i][target] != -1)
9            return dp[i][target];
10        int nottake = func(i - 1, target, nums, dp);
11        int take = 0;
12        if (target >= nums[i])
13            take = nums[i] + func(i - 1, target - nums[i], nums, dp);
14        return dp[i][target] = max(take, nottake);
15    }
16
17public:
18    int lastStoneWeightII(vector<int>& stones) {
19        int n = stones.size();
20        int sum = 0;
21        for (int x : stones)
22            sum += x;
23        int target = sum / 2;
24        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
25        int subset = func(n - 1, target, stones, dp);
26        return sum - 2 * subset;
27    }
28};