// Last updated: 7/18/2026, 2:01:48 PM
class Solution {
public:
    int cherryPickup(vector<vector<int>>& matrix) {
         int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0))
        );
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = matrix[n - 1][j1];
                else
                    dp[n - 1][j1][j2] =
                        matrix[n - 1][j1] + matrix[n - 1][j2];
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e9;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int nj1 = j1 + di;
                            int nj2 = j2 + dj;
                            if (nj1 < 0 || nj1 >= m || nj2 < 0 || nj2 >= m)
                                continue;
                            int value;
                            if (j1 == j2)
                                value = matrix[i][j1];
                            else
                                value = matrix[i][j1] + matrix[i][j2];
                            value += dp[i + 1][nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};