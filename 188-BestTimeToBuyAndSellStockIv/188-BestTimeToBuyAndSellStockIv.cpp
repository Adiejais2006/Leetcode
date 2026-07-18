// Last updated: 7/18/2026, 2:05:45 PM
class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
       vector<vector<int>>before(2 , vector<int>(k+1,0));
         vector<vector<int>>curr(2 , vector<int>(k+1,0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int t = 1; t <= k; t++) {
                    if (buy == 0) {
                       curr[buy][t] =
                            max(before[0][t],
                                -1 * arr[ind] +before[1][t]);
                    } else {
                        curr[buy][t] =
                            max(before[1][t],
                                1 * arr[ind] + before[0][t - 1]);
                    }
                }
                before = curr;
            }
        }
        return before[0][k];  
    }
};