// Last updated: 10/31/2026, 9:36:52 PM
1class Solution {
2    int func(int i, vector<int>& nums, vector<int>& dp) {
3        int n = nums.size();
4        if (i == n - 1)
5            return 0;
6        int jump = 1e9;
7        if (dp[i] != -1)
8            return dp[i];
9        for (int j = 1; j <= nums[i] && i + j < n; j++) {
10            jump = min(jump, 1 + func(i + j, nums, dp));
11        }
12        return dp[i] = jump;
13    }
14
15public:
16    int jump(vector<int>& nums) {
17        int n = nums.size();
18        vector<int> dp(n, -1);
19        return func(0, nums, dp);
20    }
21};