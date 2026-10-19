// Last updated: 10/19/2026, 4:38:14 PM
1class Solution {
2    int func(int target, vector<int>& nums, vector<int>& dp) {
3        if (target == 0)
4            return 1;
5        if (dp[target] != -1)
6            return dp[target];
7        int ways = 0;
8        for (auto it : nums) {
9            if (it <= target)
10                ways += func(target - it, nums, dp);
11        }
12        return dp[target] = ways;
13    }
14
15public:
16    int combinationSum4(vector<int>& nums, int target) {
17        int n = nums.size();
18        vector<int>dp(target + 1, -1);
19        return func(target, nums, dp);
20    }
21};