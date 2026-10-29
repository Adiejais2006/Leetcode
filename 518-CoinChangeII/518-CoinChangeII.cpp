// Last updated: 10/29/2026, 3:12:18 PM
1class Solution {
2    int func(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
3        if (amount == 0)
4            return 1;
5        if (i == coins.size() - 1) {
6            if (amount % coins[i] == 0 || amount == 0)
7                return 1;
8            return 0;
9        }
10        if (dp[i][amount] != -1)
11            return dp[i][amount];
12        int notpick = func(i + 1, amount, coins, dp);
13        int pick = 0;
14        if (amount >= coins[i])
15            pick = func(i, amount - coins[i], coins, dp);
16        return dp[i][amount] = pick + notpick;
17    }
18
19public:
20    int change(int amount, vector<int>& coins) {
21        int n =coins.size();
22        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
23        return func(0, amount, coins, dp);
24    }
25};