// Last updated: 10/22/2026, 2:53:06 PM
1class Solution {
2public:
3    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        int m = nums2.size();
6        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
7        for (int i = n - 1; i >= 0; i--) {
8            for (int j = m - 1; j >= 0; j--) {
9                if (nums1[i] == nums2[j]) {
10                    dp[i][j] = 1 + dp[i + 1][j + 1];
11                }
12                else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
13            }
14        }
15        return dp[0][0];
16    }
17};