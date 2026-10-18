// Last updated: 10/18/2026, 3:14:46 PM
1class Solution {
2    int func(int i, int j, vector<int>& nums1, vector<int>& nums2,
3             vector<vector<int>>& dp) {
4        if (i < 0 || j < 0) return 0;
5        if (dp[i][j] != -1) return dp[i][j];
6        if (nums1[i] == nums2[j]) {
7            return dp[i][j] = 1 + func(i - 1, j - 1, nums1, nums2, dp);
8        }
9        return dp[i][j] = 0;
10    }
11
12public:
13    int findLength(vector<int>& nums1, vector<int>& nums2) {
14        int n = nums1.size();
15        int m = nums2.size();
16        vector<vector<int>> dp(n, vector<int>(m, -1));
17        int ans = 0;
18
19        for (int i = 0; i < n; i++) {
20            for (int j = 0; j < m; j++) {
21                ans = max(ans, func(i, j, nums1, nums2, dp));
22            }
23        }
24
25        return ans;
26    }
27};