// Last updated: 10/21/2026, 4:53:58 PM
1class Solution {
2    int func(int i, int j, vector<int>& nums,
3             vector<vector<int>>& dp) {
4        if (i > j)
5            return 0;
6        if (dp[i][j] != -1)
7            return dp[i][j];
8        int maxi = 0;
9        for (int k = i; k <= j; k++) {
10            int coins = func(i, k - 1, nums, dp)
11                      + func(k + 1, j, nums, dp)
12                      + nums[i - 1] * nums[k] * nums[j + 1];
13            maxi = max(maxi, coins);
14        }
15        return dp[i][j] = maxi;
16    }
17
18public:
19    int maxCoins(vector<int>& nums) {
20        vector<int> arr;
21        arr.push_back(1);
22        for (auto it : nums)
23            arr.push_back(it);
24
25        arr.push_back(1);
26        int n = nums.size();
27        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
28        return func(1, n, arr, dp);
29    }
30};