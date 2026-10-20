// Last updated: 10/20/2026, 3:44:46 PM
1class Solution {
2
3public:
4    int combinationSum4(vector<int>& nums, int target) {
5        int n = nums.size();
6        std::vector<unsigned int> dp(target + 1, 0);
7        dp[0] = 1;
8        for (int i = 1; i <= target; i++) {
9            int ways = 0;
10            for (auto it : nums) {
11                if (it <= i)
12                    ways += dp[i - it];
13            }
14            dp[i] = ways;
15        }
16        return dp[target];
17    }
18};