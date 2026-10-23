// Last updated: 10/23/2026, 11:36:19 PM
1
2class Solution {
3    int MOD = 1e9 + 7;
4    vector<int> dx = {-1, 0, 0, 1};
5    vector<int> dy = {0, -1, 1, 0};
6    int func(int i, int j, int m, int n, int k,
7             vector<vector<vector<long long>>>& dp) {
8        if (i < 0 || j < 0 || i >= m || j >= n)
9            return 1;
10        if (k == 0)
11            return 0;
12        if (dp[i][j][k] != -1)
13            return dp[i][j][k];
14        int ans = 0;
15        for (int l = 0; l < 4; l++) {
16            int ni = i + dx[l];
17            int nj = j + dy[l];
18            ans = (ans + func(ni, nj, m, n, k - 1, dp)) % MOD;
19        }
20        return dp[i][j][k] = ans;
21    }
22
23public:
24    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
25        vector<vector<vector<long long>>> dp(
26            m + 1,
27            vector<vector<long long>>(n + 1, vector<long long>(maxMove + 1, -1)));
28        return func(startRow, startColumn, m, n, maxMove, dp);
29    }
30};
31