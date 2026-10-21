// Last updated: 10/21/2026, 6:26:36 PM
1class Solution {
2
3public:
4    int maxProfit(vector<int>& prices) {
5        int n = prices.size();
6        vector<int> next(2, 0);
7        vector<int> curr(2, 0);
8        for (int i = n - 1; i >= 0; i--) {
9            for (int buy = 0; buy <= 1; buy++) {
10                int profit = 0;
11                if (buy) {
12                    profit = max(next[1], -prices[i] + next[0]);
13                }
14                if (!buy) {
15                    profit = max(next[0], prices[i] + next[1]);
16                }
17                curr[buy] = profit;
18            }
19            next = curr;
20        }
21        return curr[1];
22    }
23};