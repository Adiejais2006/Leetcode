// Last updated: 10/20/2026, 9:37:46 PM
1class Solution {
2public:
3    int lengthOfLIS(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> dp(n + 1, 1);
6        int maxi = 1;
7        for (int i = 0; i < n; i++) {
8            for (int j = 0; j < i; j++) {
9                if (nums[j] < nums[i]) {
10                    dp[i] = max(1 + dp[j], dp[i]);
11                }
12            }
13            maxi = max(maxi, dp[i]);
14        }
15        return maxi;
16    }
17};