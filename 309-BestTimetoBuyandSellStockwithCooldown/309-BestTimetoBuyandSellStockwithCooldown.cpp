// Last updated: 11/9/2026, 3:56:34 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int n = prices.size();
5        vector<vector<int>> dp(n+2, vector<int>(2, 0));
6        for (int i = n - 1; i >= 0; i--) {
7            for (int buy = 1; buy >= 0; buy--) {
8                int profit = 0;
9                if (buy) {
10                    profit = max(dp[i + 1][buy], -prices[i] + dp[i + 1][0]);
11                } else {
12                    profit = max(dp[i + 1][buy], prices[i] + dp[i + 2][1]);
13                }
14                dp[i][buy] = profit;
15            }
16        }
17        return dp[0][1];
18    }
19};
20