// Last updated: 7/18/2026, 2:04:57 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2, 0);      // dp[ind+1]
        vector<int> after2(2, 0);     // dp[ind+2]
        vector<int> curr(2, 0);       // dp[ind]
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy == 1) {
                    profit = max(after[1],
                                 -prices[ind] + after[0]);
                } else {
                    profit = max(after[0],
                                 prices[ind] + after2[1]);
                }
                curr[buy] = profit;
            }
            after2 = after;
            after = curr;
        }

        return after[1];
    }
};