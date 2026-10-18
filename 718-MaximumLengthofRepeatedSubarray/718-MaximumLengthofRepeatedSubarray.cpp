// Last updated: 10/18/2026, 3:25:13 PM
1class Solution {
2    int func(int i, int j, vector<int>& nums1, vector<int>& nums2,
3             vector<vector<int>>& dp) {
4        if (i == 0 || j == 0)
5            return 0;
6        if (dp[i][j] != -1)
7            return dp[i][j];
8        if (nums1[i-1] == nums2[j-1]) {
9            return dp[i][j] = 1 + func(i - 1, j - 1, nums1, nums2, dp);
10        }
11        return dp[i][j] = 0;
12    }
13
14public:
15    int findLength(vector<int>& nums1, vector<int>& nums2) {
16        int n = nums1.size();
17        int m = nums2.size();
18        int ans = 0;
19        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
20        for (int i = n ; i >= 0; i--) {
21            for (int j = m ; j >= 0; j--) {
22                ans = max(ans, func(i, j, nums1, nums2, dp));
23            }
24        }
25        return ans;
26    }
27};