// Last updated: 10/21/2026, 6:07:53 PM
1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4         int mino = 1e9;
5        int ans = -1;
6        for (int i = 0; i < prices.size(); i++) {
7            if (prices[i] < mino) mino = prices[i];
8            int profit = prices[i] - mino;
9            ans = max(ans, profit);
10        }
11
12        return ans;
13    }
14};