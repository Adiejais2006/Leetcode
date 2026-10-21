// Last updated: 10/21/2026, 7:15:38 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int n = prices.size();
5        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
6        for (int i = n - 1; i >= 0; i--) {
7            for (int buy = 0; buy <= 1; buy++) {
8                int profit = 0;
9                if (buy) {
10                    profit = max(dp[i + 1][1], -prices[i] + dp[i + 1][0]);
11                }
12                if (!buy) {
13                    profit = max(dp[i + 1][0],  prices[i] + dp[i + 2][1]);
14                }
15                dp[i][buy] = profit;
16            }
17        }
18        return dp[0][1];
19    }
20};