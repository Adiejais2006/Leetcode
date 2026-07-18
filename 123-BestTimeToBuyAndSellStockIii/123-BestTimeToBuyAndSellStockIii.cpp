// Last updated: 7/18/2026, 2:06:18 PM
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> before(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int t = 1; t <= 2; t++) {
                    if (buy == 0) {
                        curr[buy][t] =
                            max(before[0][t], -1 * arr[ind] + before[1][t]);
                    } else {
                        curr[buy][t] =
                            max(before[1][t], 1 * arr[ind] + before[0][t - 1]);
                    }
                }
                before =curr;
            }
        }
        return curr[0][2];
    }
};