// Last updated: 10/31/2026, 4:56:36 PM
1class Solution {
2    int func(int i, int t, vector<int>& nums,vector<vector<int>>&dp) {
3        if(t==0)return true;
4        if(i==nums.size()-1)return t==nums[i];
5        if( dp[i][t]!=-1)return  dp[i][t];
6        int nottake = func(i + 1, t, nums,dp);
7        int take = false;
8        if (nums[i] <= t) {
9            take = func(i + 1, t - nums[i], nums,dp);
10        }
11        return dp[i][t]=  take || nottake;
12    }
13public:
14    bool canPartition(vector<int>& nums) {
15        int n = nums.size();
16        int sum = 0;
17        for (auto it : nums)
18            sum += it;
19        if (sum % 2 == 1)
20            return 0;
21        vector<vector<int>>dp(n, vector<int>(sum/2+1,-1));
22        return func(0, sum/2, nums,dp);
23    }
24};