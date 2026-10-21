// Last updated: 10/21/2026, 6:10:52 PM
1class Solution {
2
3public:
4    int maxProfit(vector<int>& prices) {
5        int n = prices.size();
6        int ans = -1;
7        int mini = 1e9;
8        for (int i = 0; i < n; i++) {
9            mini = min(mini, prices[i]);
10            ans = max(ans, prices[i] - mini);
11        }
12        return ans == -1 ? 0 : ans;
13    }
14};