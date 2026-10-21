// Last updated: 10/21/2026, 9:35:04 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices, int fee) {
4        int n = prices.size();
5        vector<int> next(2, 0);
6        vector<int> curr(2, 0);
7        for (int i = n - 1; i >= 0; i--) {
8            for (int buy = 0; buy <= 1; buy++) {
9                int profit = 0;
10                if (buy) {
11                    profit = max(next[1], -prices[i] + next[0]);
12                }
13                if (!buy) {
14                    profit = max(next[0], prices[i] + next[1]-fee);
15                }
16                curr[buy] = profit;
17            }
18            next = curr;
19        }
20        return curr[1];
21    }
22};