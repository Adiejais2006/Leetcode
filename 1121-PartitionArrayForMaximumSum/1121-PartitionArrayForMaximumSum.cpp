// Last updated: 7/18/2026, 2:02:38 PM
class Solution {

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(k+1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            int maxi = 0;
            int ans = 0;
            for (int j = ind; j < min((int)arr.size(), ind + k); j++) {
                maxi = max(maxi, arr[j]);
                int len = j - ind + 1;
                ans = max(ans, len * maxi + dp[j + 1][k]);
            }

            dp[ind][k] = ans;
        }
        return dp[0][k];
    }
};