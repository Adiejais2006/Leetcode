// Last updated: 10/20/2026, 4:38:17 PM
1class Solution {
2public:
3    int func(int i, vector<int>& nums, int target,
4             map<pair<int, int>, int>& dp) {
5        if (i == 0) {
6            int ways = 0;
7            if (target == -nums[0])
8                ways++;
9            if (target == nums[0])
10                ways++;
11            return ways;
12        }
13        if (dp.find({i, target}) != dp.end())
14            return dp[{i, target}];
15        int plus = func(i - 1, nums, target - nums[i], dp);
16        int minus = func(i - 1, nums, target + nums[i], dp);
17        return dp[{i, target}] = plus + minus;
18    }
19    int findTargetSumWays(vector<int>& nums, int target) {
20        map<pair<int, int>, int> dp;
21        return func(nums.size() - 1, nums, target, dp);
22    }
23};