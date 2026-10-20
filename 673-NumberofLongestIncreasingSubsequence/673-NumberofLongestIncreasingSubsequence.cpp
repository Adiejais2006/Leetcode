// Last updated: 10/20/2026, 9:43:30 PM
1class Solution {
2public:
3    int findNumberOfLIS(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> dp(n + 1, 1);
6        vector<int> count(n + 1, 1);
7        int maxi = 1;
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < i; j++) {
10                if (nums[j] < nums[i]) {
11                    if (1 + dp[j] > dp[i]) {
12                        dp[i] = 1 + dp[j];
13                        count[i] = count[j];
14                    } else if (dp[i] == dp[j] + 1)
15                        count[i] += count[j];
16                }
17            }
18            maxi = max(maxi, dp[i]);
19        }
20        int ans = 0;
21        for (int i = 0; i < n; i++) {
22            if (dp[i] == maxi)
23                ans += count[i];
24        }
25        return ans;
26    }
27};