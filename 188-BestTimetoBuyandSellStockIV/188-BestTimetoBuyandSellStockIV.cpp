// Last updated: 10/21/2026, 7:01:48 PM
1class Solution {
2public:
3    int maxProfit(int k, vector<int>& prices) {
4        int n = prices.size();
5        vector<vector<int>> prev(2, vector<int>(k+1, 0));
6        vector<vector<int>> curr(2, vector<int>(k+1, 0));
7        for (int i = n - 1; i >= 0; i--) {
8            for (int buy = 0; buy <= 1; buy++) {
9                for (int times = 1; times <= k; times++) {
10                    int profit = 0;
11                    if (buy) {
12                        profit =
13                            max(prev[1][times], -prices[i] + prev[0][times]);
14                    }
15                    if (!buy) {
16                        profit =
17                            max(prev[0][times], prices[i] + prev[1][times - 1]);
18                    }
19                    curr[buy][times] = profit;
20                }
21                prev = curr;
22            }
23        }
24        return prev[1][k];
25    }
26};