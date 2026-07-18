// Last updated: 7/18/2026, 2:04:56 PM
class Solution {
public:
    int maxCoins(vector<int>& nums) {
         int n = nums.size();

        vector<int> arr;
        arr.push_back(1);

        for (int x : nums) {
            arr.push_back(x);
        }

        arr.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {

                int maxi = 0;

                for (int k = i; k <= j; k++) {

                    int cost = arr[i - 1] * arr[k] * arr[j + 1] +
                               dp[i][k - 1] +
                               dp[k + 1][j];

                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};