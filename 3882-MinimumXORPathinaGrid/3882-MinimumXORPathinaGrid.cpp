// Last updated: 10/28/2026, 2:24:29 PM
1class Solution {
2public:
3    int minVal = INT_MAX;
4    int minCost(vector<vector<int>>& grid) {
5        int m = grid.size();
6        int n = grid[0].size();
7        minVal = INT_MAX;
8        vector<vector<vector<bool>>> dp(
9            m, vector<vector<bool>>(n, vector<bool>(1024, false)));
10        rec(grid, 0, 0, 0, dp);
11        return minVal;
12    }
13    void rec(vector<vector<int>>& grid, int i, int j, int curr,
14             vector<vector<vector<bool>>>& dp) {
15        int m = grid.size();
16        int n = grid[0].size();
17        if (i >= m || j >= n) {
18            return;
19        }
20        if (i == m - 1 && j == n - 1) {
21            minVal = min(minVal, curr ^ grid[i][j]);
22            return;
23        }
24        if (dp[i][j][curr]) {
25            return;
26        }
27        dp[i][j][curr] = true;
28        int nextXor = curr ^ grid[i][j];
29        rec(grid, i, j + 1, nextXor, dp);
30        rec(grid, i + 1, j, nextXor, dp);
31    }
32};