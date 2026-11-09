// Last updated: 11/9/2026, 3:53:46 PM
1class Solution {
2    int func(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
3        if (i >= prices.size())
4            return 0;
5        int profit = 0;
6        if (dp[i][buy] != -1)
7            return dp[i][buy];
8        if (buy) {
9            profit = max(func(i + 1, buy, prices, dp),
10                         -prices[i] + func(i + 1, 0, prices, dp));
11        } else {
12            profit = max(func(i + 1, buy, prices, dp),
13                         prices[i] + func(i + 2, 1, prices, dp));
14        }
15        return dp[i][buy] = profit;
16    }
17
18public:
19    int maxProfit(vector<int>& prices) {
20        int n = prices.size();
21        vector<vector<int>> dp(n, vector<int>(2, -1));
22        return func(0, 1, prices, dp);
23    }
24};
25