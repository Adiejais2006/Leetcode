// Last updated: 10/19/2026, 11:48:07 AM
1class Solution {
2    bool func(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
3        if (target == 0)
4            return true;
5        if (i == 0 ) return target == nums[i];
6        if (dp[i][target] != -1)
7            return dp[i][target];
8        bool nottake = func(i - 1, target, nums, dp);
9        bool take = 0;
10        if (target >= nums[i])
11            take = func(i - 1, target - nums[i], nums, dp);
12        return dp[i][target] = take || nottake;
13    }
14
15public:
16    bool canPartition(vector<int>& nums) {
17        int sum = 0;
18        int n = nums.size();
19        for (int i = 0; i < n; i++)
20            sum += nums[i];
21        if (sum % 2 == 1)
22            return false;
23        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
24        return func(n - 1, sum / 2, nums, dp);
25    }
26};