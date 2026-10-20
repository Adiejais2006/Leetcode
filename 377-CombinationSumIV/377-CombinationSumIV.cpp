// Last updated: 10/20/2026, 3:38:04 PM
1class Solution {
2    int func(int target , vector<int> &nums, vector<int> &dp){
3        if(target==0) return 1;
4        if(dp[target]!=-1) return dp[target];
5        int ways = 0 ;
6        for(auto it:nums){
7            if(it<=target)
8            ways+= func(target - it , nums,dp);
9        }
10        return dp[target] =  ways;
11    }
12public:
13    int combinationSum4(vector<int>& nums, int target) {
14        int n = nums.size();
15        vector<int> dp(target+1 , -1);
16        return func(target , nums,dp);
17    }
18};