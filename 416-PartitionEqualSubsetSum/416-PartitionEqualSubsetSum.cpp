// Last updated: 10/19/2026, 11:59:11 AM
1class Solution {
2public:
3    bool canPartition(vector<int>& nums) {
4        int sum = 0;
5        int n = nums.size();
6        for (int i = 0; i < n; i++)
7            sum += nums[i];
8        if (sum % 2 == 1)
9            return false;
10        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, 0));
11        for (int i = 0; i < n; i++)
12            dp[i][0] = 1;
13        if (nums[0] <= sum/2) {
14            dp[0][nums[0]] = true;
15        }
16        for (int i = 1; i < n; i++) {
17            for (int target = 0; target <= sum / 2; target++) {
18                bool nottake = dp[i - 1][target];
19                bool take = 0;
20                if (target >= nums[i])
21                    take = dp[i - 1][target - nums[i]];
22                dp[i][target] = take || nottake;
23            }
24        }
25        return dp[n - 1][sum / 2];
26    }
27};