// Last updated: 10/20/2026, 8:14:20 PM
1class Solution {
2    int func(int i, vector<int>& nums, int prev, vector<vector<int>>& dp) {
3        if (i < 0)
4            return 0;
5        if (dp[i][prev+1] != -1)
6            return dp[i][prev+1];
7        int nottpick = func(i - 1, nums, prev, dp);
8        int pick = 0;
9        if ( prev == -1 || nums[i] < nums[prev])
10            pick = 1 + func(i - 1, nums, i, dp);
11        return dp[i][prev+1] = max(pick, nottpick);
12    }
13
14public:
15    int lengthOfLIS(vector<int>& nums) {
16        int n = nums.size();
17        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
18        return func(n - 1, nums, -1, dp);
19    }
20};