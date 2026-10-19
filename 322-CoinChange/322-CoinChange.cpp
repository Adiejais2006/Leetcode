// Last updated: 10/19/2026, 3:10:36 PM
1class Solution {
2
3public:
4    int coinChange(vector<int>& coins, int a) {
5        int n = coins.size();
6        vector<vector<int>> dp(n, vector<int>(a + 1, 0));
7        for (int i = 0; i < n; i++)
8            dp[i][0] = 0;
9        for (int i = 0; i <= a; i++) {
10            if (i % coins[0] == 0)
11                dp[0][i] = i / coins[0];
12            else
13                dp[0][i] = 1e9;
14        }
15        for (int i = 1; i < n; i++) {
16            for (int amount = 0; amount <= a; amount++) {
17                int nottake = dp[i - 1][amount];
18                int take = 1e9;
19                if (amount >= coins[i]) {
20                    take = 1 + dp[i][amount - coins[i]];
21                }
22                dp[i][amount] = min(take, nottake);
23            }
24        }
25        int ans = dp[n - 1][a];
26        return (ans == 1e9) ? -1 : ans;
27    }
28};