// Last updated: 10/21/2026, 6:19:44 PM
1class Solution {
2    int func(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
3        if (i == prices.size()) {
4           return 0 ;
5        }
6        if (dp[i][buy] != -1)
7            return dp[i][buy];
8        int profit = 0;
9        if (buy) {
10            profit = max(func(i + 1, 1, prices, dp),
11                         -prices[i] + func(i + 1, 0, prices, dp));
12        }
13        if (!buy) {
14            profit = max(func(i + 1, 0, prices, dp),
15                         prices[i] + func(i + 1, 1, prices, dp));
16        }
17        return dp[i][buy] = profit;
18    }
19
20public:
21    int maxProfit(vector<int>& prices) {
22        int n = prices.size();
23        vector<vector<int>> dp(n+1, vector<int>(2, -1));
24        return func(0, 1, prices, dp);
25    }
26};