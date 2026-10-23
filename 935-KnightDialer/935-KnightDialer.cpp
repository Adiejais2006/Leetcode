// Last updated: 10/23/2026, 9:24:08 PM
1class Solution {
2    int MOD = 1e9 + 7;
3public:
4    int knightDialer(int n) {
5        vector<vector<int>> moves = {{4, 6},    {6, 8}, {7, 9},    {8, 4},
6                                     {9, 0, 3}, {},     {0, 7, 1}, {2, 6},
7                                     {1, 3},    {2, 4}};
8        vector<vector<int>> dp(10, vector<int>(n, 0));
9        for (int i = 0; i < 10; i++)
10            dp[i][0] = 1;
11        for (int total = 1; total < n; total++) {
12            for (int i = 0; i < 10; i++) {
13                int ways = 0;
14                for (int it : moves[i]) {
15                    ways = (ways + dp[it][total - 1]) % MOD;
16                }
17                dp[i][total] = ways;
18            }
19        }
20
21        int ans = 0;
22        for (int i = 0; i < 10; i++)
23            ans = (ans + dp[i][n - 1]) % MOD;
24        return ans;
25    }
26};