// Last updated: 10/24/2026, 4:29:45 PM
1class Solution {
2    int func(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
3          if (i == 0) {
4            if (target == 0 && nums[0] == 0) return 2;
5            if (target == 0 || target == nums[0]) return 1;
6            return 0;
7        }
8        if (i < 0)
9            return 0;
10        if (dp[i][target] != -1)
11            return dp[i][target];
12        int nottake = func(i - 1, target, nums, dp);
13        int take = 0;
14        if (target >= nums[i]) {
15            take = func(i - 1, target - nums[i], nums, dp);
16        }
17        return dp[i][target] = take + nottake;
18    }
19
20public:
21    int findTargetSumWays(vector<int>& nums, int target) {
22        int n = nums.size();
23        int sum = 0;
24        for (auto it : nums)
25            sum += it;
26        if ((sum + target) % 2 != 0)
27            return 0;
28        if (abs(target) > sum)
29            return 0;
30        int tar = (sum + target) / 2;
31        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
32        return func(n - 1, tar, nums, dp);
33    }
34};