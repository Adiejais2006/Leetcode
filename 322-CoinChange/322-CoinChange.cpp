// Last updated: 10/19/2026, 3:03:38 PM
1class Solution {
2    int func(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
3        if (amount == 0)
4            return 0;
5        if (i == 0) {
6            if (amount % coins[0] == 0)
7                return amount / coins[0];
8            return 1e9;
9        }
10        if (dp[i][amount] != -1)
11            return dp[i][amount];
12        int nottake = func(i - 1, amount, coins, dp);
13        int take = 1e9;
14        if (amount >= coins[i]) {
15            take = 1 + func(i, amount - coins[i], coins, dp);
16        }
17        return dp[i][amount] = min(take, nottake);
18    }
19
20public:
21    int coinChange(vector<int>& coins, int amount) {
22        int n = coins.size();
23        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
24        int ans = func(n - 1, amount, coins, dp);
25        return (ans == 1e9) ? -1 : ans;
26    }
27};