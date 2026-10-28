// Last updated: 10/28/2026, 11:39:49 PM
1class Solution { int func(int i, int j1, int j2, int n, int m, vector<vector<int>> &matrix,
2             vector<vector<vector<int>>> &dp) {
3        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;
4        if (i == n - 1) {
5            if (j1 == j2)
6                return matrix[i][j1];
7            else
8                return matrix[i][j1] + matrix[i][j2];
9        }
10        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
11        int maxi = INT_MIN;
12        for (int di = -1; di <= 1; di++) {
13            for (int dj = -1; dj <= 1; dj++) {
14                int ans;
15                if (j1 == j2)
16                    ans = matrix[i][j1] +
17                          func(i + 1, j1 + di, j2 + dj, n, m, matrix, dp);
18                else
19                    ans = matrix[i][j1] + matrix[i][j2] +
20                          func(i + 1, j1 + di, j2 + dj, n, m, matrix, dp);
21                maxi = max(maxi, ans);
22            }
23        }
24        return dp[i][j1][j2] = maxi;
25    }
26
27public:
28    int cherryPickup(vector<vector<int>>& matrix) {
29          int n = matrix.size();
30        int m = matrix[0].size();
31        vector<vector<vector<int>>> dp(
32            n, vector<vector<int>>(m, vector<int>(m, -1)));
33        return func(0, 0, m - 1, n, m, matrix, dp);
34    }
35};