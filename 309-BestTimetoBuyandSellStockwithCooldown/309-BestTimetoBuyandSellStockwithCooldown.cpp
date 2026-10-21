// Last updated: 10/21/2026, 7:16:57 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int n = prices.size();
5        vector<int> prev(2, 0);
6        vector<int> prev2(2, 0);
7        vector<int> curr(2, 0);
8        for (int i = n - 1; i >= 0; i--) {
9            for (int buy = 0; buy <= 1; buy++) {
10                int profit = 0;
11                if (buy) {
12                    profit = max(prev[1], -prices[i] + prev[0]);
13                }
14                if (!buy) {
15                    profit = max(prev[0],  prices[i] + prev2[1]);
16                }
17                curr[buy] = profit;
18            }
19            prev2 = prev;
20            prev =curr;
21        }
22        return prev[1];
23    }
24};