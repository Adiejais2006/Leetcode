// Last updated: 10/20/2026, 4:46:25 PM
1class Solution {
2public:
3    int findTargetSumWays(vector<int>& nums, int target) {
4        int n = nums.size();
5        int sum = 0;
6        for (auto it : nums)
7            sum += it;
8        if (abs(target) > sum)
9            return 0;
10        map<pair<int, int>, int> dp;
11        for (int j = -sum; j <= sum; j++) {
12            int ways = 0;
13            if (j == -nums[0])
14                ways++;
15            if (j == nums[0])
16                ways++;
17            dp[{0, j}] = ways;
18        }
19        for (int i = 1; i < n; i++) {
20            for (int j = -sum; j <= sum; j++) {
21                int plus = dp[{i - 1, j - nums[i]}];
22                int minus = dp[{i - 1, j + nums[i]}];
23                dp[{i, j}] = plus + minus;
24            }
25        }
26        return dp[{n - 1, target}];
27    }
28};