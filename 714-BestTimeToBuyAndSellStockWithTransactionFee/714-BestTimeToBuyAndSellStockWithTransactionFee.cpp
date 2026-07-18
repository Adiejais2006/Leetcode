// Last updated: 7/18/2026, 2:03:40 PM
class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
         vector<int> after(2, 0);
        vector<int> curr(2, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) {
                    curr[buy] = max(after[0], -1 * arr[ind] + after[1]);
                } else {
                    curr[buy] = max(after[1], 1 * arr[ind] + after[0] - fee);
                }
            }
            after = curr;
        }
        return curr[0];
    }
};