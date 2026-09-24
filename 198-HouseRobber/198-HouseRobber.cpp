// Last updated: 9/24/2026, 1:28:23 PM
1class Solution {
2public:
3    int rob(vector<int>& nums) {
4         int n = nums.size();
5        vector<int> dp(n + 1, -1);
6        dp[0] = nums[0];
7        for (int i = 1; i < n; i++) {
8            int left = nums[i] ;
9          if(i>1) left = nums[i] + dp[i-2];
10          int right = dp[i-1];
11          dp[i] = max(left,right);
12        }
13
14        return dp[n - 1];
15    }
16};