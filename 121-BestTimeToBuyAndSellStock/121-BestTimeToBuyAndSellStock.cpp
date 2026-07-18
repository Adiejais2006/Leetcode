// Last updated: 7/18/2026, 2:06:20 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int mino = 1e9;
        int ans = -1;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < mino) mino = prices[i];
            int profit = prices[i] - mino;
            ans = max(ans, profit);
        }

        return ans;
    }
};