// Last updated: 10/23/2026, 6:37:50 PM
1class Solution {
2public:
3    int longestArithSeqLength(vector<int>& nums) {
4        int n = nums.size();
5        vector<unordered_map<int, int>> dp(n);
6        int ans = 2;
7        for (int i = 0; i < n; i++) {
8            for (int j = 0; j < i; j++) {
9                int diff = nums[i] - nums[j];
10                int len = 2;
11                if (dp[j].count(diff)) {
12                    len = dp[j][diff] + 1;
13                }
14                dp[i][diff] = max(dp[i][diff], len);
15                ans = max(ans, dp[i][diff]);
16            }
17        }
18        return ans;
19    }
20};
21