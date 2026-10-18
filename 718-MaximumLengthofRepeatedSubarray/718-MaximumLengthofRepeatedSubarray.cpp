// Last updated: 10/18/2026, 3:28:15 PM
1class Solution {
2public:
3    int findLength(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        int m = nums2.size();
6        int ans = 0;
7        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
8        for (int i = 1; i <= n; i++) {
9            for (int j = 1; j <= m; j++) {
10                if (nums1[i - 1] == nums2[j - 1]) {
11                    dp[i][j] = 1 + dp[i - 1][j - 1];
12                } else {
13                    dp[i][j] = 0;
14                }
15
16                ans = max(ans, dp[i][j]);
17            }
18        }
19
20        return ans;
21    }
22};