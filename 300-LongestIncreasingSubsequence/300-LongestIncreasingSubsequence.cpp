// Last updated: 11/3/2026, 11:16:13 PM
1class Solution {
2public:
3    int lengthOfLIS(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> dp(n, 1);
6        int maxi = -1;
7        for (int i = 0; i < n; i++) {
8            for (int j = 0; j < i; j++) {
9                if (nums[j] < nums[i]) {
10                    if (1 + dp[j] > dp[i]) {
11                        dp[i] = max(1 + dp[j], dp[i]);
12                    }
13                }
14            }
15            maxi = max(maxi, dp[i]);
16        }
17        return maxi;
18    }
19};