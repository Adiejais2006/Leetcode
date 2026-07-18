// Last updated: 7/18/2026, 2:03:46 PM
class Solution {
    vector<vector<vector<double>>> dp;

    double solve(int n, int k, int r, int c) {
        if (r < 0 || c < 0 || r >= n || c >= n)
            return 0.0;

        if (k == 0)
            return 1.0;

        if (dp[k][r][c] != -1)
            return dp[k][r][c];

        int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[8] = { 1,  2, 2, 1,-1,-2, -2, -1};

        double ans = 0.0;

        for (int i = 0; i < 8; i++) {
            ans += solve(n, k - 1, r + dx[i], c + dy[i]);
        }

        return dp[k][r][c] = ans / 8.0;
    }

public:
    double knightProbability(int n, int k, int row, int column) {
        dp.assign(k + 1,
                  vector<vector<double>>(n,
                  vector<double>(n, -1)));

        return solve(n, k, row, column);
    }
};