// Last updated: 7/18/2026, 2:06:19 PM
   int func(vector<int> &arr, int n) {
        vector<long> ahead(2, 0);
        vector<long> cur(2, 0);

        ahead[0] = ahead[1] = 0;

        int profit;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) {
                    profit = max(0 + ahead[0], (-1) * arr[ind] + ahead[1]);
                }

                if (buy == 1) {
                    profit = max(0 + ahead[1], arr[ind] + ahead[0]);
                }
                cur[buy] = profit;
            }

            ahead = cur;
        }

        return cur[0];
    }class Solution {
public:
    int maxProfit(vector<int>& prices) {
         return func(prices, prices.size());
    }
};