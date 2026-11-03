// Last updated: 11/3/2026, 10:56:06 PM
1class Solution {
2    int func(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
3        if (i < 0)
4            return 0;
5        if (dp[i][prev+1] != -1)
6            return dp[i][prev+1];
7        int nottake = func(i - 1, prev, nums, dp);
8        int take = 0;
9        if (prev == -1 || nums[i] < nums[prev]) {
10            take = 1 + func(i - 1, i, nums, dp);
11        }
12        return dp[i][prev+1] = max(nottake, take);
13    }
14
15public:
16    int lengthOfLIS(vector<int>& nums) {
17        int n = nums.size();
18        vector<vector<int>> dp(n, vector<int>(n+1, -1));
19        return func(n - 1, -1, nums, dp);
20    }
21};