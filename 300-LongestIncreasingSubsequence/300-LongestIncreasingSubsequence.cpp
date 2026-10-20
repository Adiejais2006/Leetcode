// Last updated: 10/20/2026, 8:27:05 PM
1
2class Solution {
3public:
4    int lengthOfLIS(vector<int>& nums) {
5        int n = nums.size();
6        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
7        for (int i = 0; i < n; i++) {
8            for (int prev = -1; prev < n; prev++) {
9                int notpick = (i > 0) ? dp[i - 1][prev + 1] : 0;
10                int pick = 0;
11                if (prev == -1 || nums[i] < nums[prev]) {
12                    pick = 1 + ((i > 0) ? dp[i - 1][i + 1] : 0);
13                }
14                dp[i][prev + 1] = max(pick, notpick);
15            }
16        }
17
18        return dp[n - 1][0];
19    }
20};
21