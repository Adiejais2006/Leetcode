// Last updated: 10/23/2026, 9:32:20 PM
1class Solution {
2    int MOD = 1e9 + 7;
3    int func(int digit, int total, vector<vector<int>>& nums,
4             vector<vector<int>>& dp) {
5        if (total == 0)
6            return 1;
7        if (dp[digit][total] != -1)
8            return dp[digit][total];
9        int ways = 0;
10        for (auto it : nums[digit]) {
11            ways = (ways + func(it, total - 1, nums, dp)) % MOD;
12        }
13        return dp[digit][total] = ways;
14    }
15
16public:
17    int knightDialer(int n) {
18        vector<vector<int>> moves = {{4, 6},    {6, 8}, {7, 9},    {8, 4},
19                                     {9, 0, 3}, {},     {0, 7, 1}, {2, 6},
20                                     {1, 3},    {2, 4}};
21        int ans = 0;
22        vector<vector<int>> dp(10, vector<int>(n+1, -1));
23        for (int i = 0; i <= 9; i++) {
24            ans = (ans + func(i, n - 1, moves, dp)) % MOD;
25        }
26        return ans;
27    }
28};