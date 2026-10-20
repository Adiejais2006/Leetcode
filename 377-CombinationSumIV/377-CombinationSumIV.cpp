// Last updated: 10/20/2026, 3:44:18 PM
1class Solution {
2public:
3    int combinationSum4(std::vector<int>& nums, int target) {
4        std::vector<unsigned int> dp(target + 1, 0);
5        dp[0] = 1;
6        
7        for (int i = 1; i <= target; ++i) {
8            for (int num : nums) {
9                if (i - num >= 0) {
10                    dp[i] += dp[i - num];
11                }
12            }
13        }
14        
15        return dp[target];
16    }
17};