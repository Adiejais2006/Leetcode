// Last updated: 7/18/2026, 2:01:42 PM
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {

            for (int i = 0; i + len < m; i++) {

                int j = i + len;

                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(
                        dp[i][j],
                        cuts[j] - cuts[i] +
                        dp[i][k] +
                        dp[k][j]
                    );
                }

                if (dp[i][j] == INT_MAX)
                    dp[i][j] = 0;
            }
        }

        return dp[0][m - 1];
    }
};