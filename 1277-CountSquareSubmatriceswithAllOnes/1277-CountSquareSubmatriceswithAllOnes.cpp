// Last updated: 10/23/2026, 3:54:08 PM
1class Solution {
2
3    int func(int i, int j, vector<vector<int>>& matrix,
4             vector<vector<int>>& dp) {
5        if (i < 0 || j < 0)
6            return 0;
7        if (matrix[i][j] == 0)
8            return 0;
9        if (dp[i][j] != -1)
10            return dp[i][j];
11        int top = 1 + func(i - 1, j, matrix, dp);
12        int left = 1 + func(i, j - 1, matrix, dp);
13        int topleft = 1 + func(i - 1, j - 1, matrix, dp);
14        return dp[i][j] = min(top, min(left, topleft));
15    }
16
17public:
18    int countSquares(vector<vector<int>>& matrix) {
19        int n = matrix.size();
20        int m = matrix[0].size();
21        int ans = 0;
22        vector<vector<int>> dp(n, vector<int>(m, -1));
23        for (int i = 0; i < n; i++) {
24            for (int j = 0; j < m; j++) {
25                ans += func(i, j, matrix, dp);
26            }
27        }
28        return ans;
29    }
30};
31