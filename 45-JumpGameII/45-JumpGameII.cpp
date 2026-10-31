// Last updated: 10/31/2026, 9:38:50 PM
1class Solution {
2
3public:
4    int jump(vector<int>& nums) {
5        int n = nums.size();
6        vector<int> dp(n, 0);
7        for (int i = n -2; i >= 0; i--) {
8            int jump = 1e9;
9            for (int j = 1; j <= nums[i] && i + j < n; j++) {
10                jump = min(jump, 1 + dp[i + j]);
11            }
12            dp[i] = jump;
13        }
14        return dp[0];
15    }
16};