// Last updated: 10/19/2026, 3:02:08 PM
1class Solution {
2    int func(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
3        if (amount == 0)
4            return 0;
5        if (i == 0) {
6            if (amount % coins[0] == 0)
7                return amount / coins[0];
8            return 1e9;
9        }
10        if( dp[i][amount]!=-1) return  dp[i][amount];
11        int nottake = func(i - 1, amount, coins, dp);
12        int take = 1e9;
13        if (amount >= coins[i]) {
14            int res = func(i, amount - coins[i], coins, dp);
15            if (res != 1e9)
16                take = 1 + res;
17        }
18        return dp[i][amount] =  min(take, nottake);
19    }
20
21public:
22    int coinChange(vector<int>& coins, int amount) {
23        int n = coins.size();
24        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
25        int ans = func(n - 1, amount, coins, dp);
26        return (ans == 1e9) ? -1 : ans;
27    }
28};