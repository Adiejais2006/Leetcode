// Last updated: 11/3/2026, 11:08:58 PM
1class Solution {
2    int func(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
3        if (i < 0)
4            return 0;
5        if (dp[i][prev + 1] != -1)
6            return dp[i][prev + 1];
7        int nottake = func(i - 1, prev, nums, dp);
8        int take = 0;
9        if (prev == -1 || nums[i] < nums[prev]) {
10            take = 1 + func(i - 1, i, nums, dp);
11        }
12        return dp[i][prev + 1] = max(nottake, take);
13    }
14
15    int tab(vector<int>& nums) {
16        int n = nums.size();
17        if (n == 0)
18            return 0;
19        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
20        dp[0][0] = 1;
21        for (int prev = 1; prev < n; prev++) {
22            if (nums[0] < nums[prev]) {
23                dp[0][prev + 1] = 1;
24            }
25        }
26        for (int i = 1; i < n; i++) {
27            for (int prev = -1; prev < n; prev++) {
28                int nottake = dp[i - 1][prev + 1];
29                int take = 0;
30                if (prev == -1 || nums[i] < nums[prev]) {
31                    take = 1 + dp[i - 1][i + 1];
32                }
33                dp[i][prev + 1] = max(nottake, take);
34            }
35        }
36        return dp[n - 1][-1 + 1];
37    }
38
39public:
40    int lengthOfLIS(vector<int>& nums) {
41        int n = nums.size();
42        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
43        return tab(nums);
44    }
45};