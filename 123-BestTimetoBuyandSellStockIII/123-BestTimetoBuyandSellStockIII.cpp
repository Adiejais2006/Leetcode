// Last updated: 10/21/2026, 6:47:32 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int n = prices.size();
5        vector<vector<vector<int>>> dp(
6            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
7        for (int i = n - 1; i >= 0; i--) {
8            for (int buy = 0; buy <= 1; buy++) {
9                for (int times = 1; times <= 2; times++) {
10                    int profit = 0;
11                    if (buy) {
12                        profit = max(dp[i + 1][1][times],
13                                     -prices[i] + dp[i + 1][0][times]);
14                    }
15                    if (!buy) {
16                        profit = max(dp[i + 1][0][times],
17                                     prices[i] + dp[i + 1][1][times - 1]);
18                    }
19                    dp[i][buy][times] = profit;
20                }
21            }
22        }
23        return dp[0][1][2];
24    }
25};