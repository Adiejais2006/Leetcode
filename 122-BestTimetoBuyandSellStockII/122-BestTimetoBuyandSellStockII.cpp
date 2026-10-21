// Last updated: 10/21/2026, 6:25:00 PM
1class Solution {
2
3public:
4    int maxProfit(vector<int>& prices) {
5        int n = prices.size();
6        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
7        for (int i = n-1; i >= 0; i--) {
8            for (int buy = 0; buy <= 1; buy++) {
9                int profit = 0;
10                if (buy) {
11                    profit = max(dp[i + 1][1], -prices[i] + dp[i + 1][0]);
12                }
13                if (!buy) {
14                    profit = max(dp[i + 1][0], prices[i] + dp[i + 1][1]);
15                }
16                dp[i][buy] = profit;
17            }
18        }
19        return dp[0][1];
20    }
21};