// Last updated: 10/22/2026, 2:47:50 PM
1class Solution {
2    int func(int i, int j, vector<int>& nums1, vector<int>& nums2,
3             vector<vector<int>>& dp) {
4        if (i == nums1.size() || j == nums2.size())
5            return 0;
6        if (dp[i][j] != -1)
7            return dp[i][j];
8        if (nums1[i] == nums2[j]) {
9            return dp[i][j] = 1 + func(i + 1, j + 1, nums1, nums2, dp);
10        }
11
12        return dp[i][j] = max(func(i + 1, j, nums1, nums2, dp),
13                              func(i, j + 1, nums1, nums2, dp));
14    }
15
16public:
17    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
18        int n = nums1.size();
19        int m = nums2.size();
20        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
21        return func(0, 0, nums1, nums2, dp);
22    }
23};