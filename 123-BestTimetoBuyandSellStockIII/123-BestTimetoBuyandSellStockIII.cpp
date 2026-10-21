// Last updated: 10/21/2026, 6:50:37 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& arr) {
4        int n = arr.size();
5         vector<vector<vector<int>>> dp(
6            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
7        for (int ind = n - 1; ind >= 0; ind--) {
8            for (int buy = 0; buy <= 1; buy++) {
9                for (int t = 1; t <= 2; t++) {
10                    int profit = 0;
11                    if (buy == 0) {
12                        profit = max(dp[ind + 1][0][t],
13                                     -1 * arr[ind] + dp[ind + 1][1][t]);
14                    } else {
15                        profit = max(dp[ind + 1][1][t],
16                                     1 * arr[ind] + dp[ind + 1][0][t-1]);
17                    }
18                    dp[ind][buy][t] = profit;
19                }
20            }
21        }
22        return dp[0][0][2];
23    }
24};