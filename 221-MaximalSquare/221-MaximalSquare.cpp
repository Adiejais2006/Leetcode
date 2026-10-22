// Last updated: 10/22/2026, 3:55:18 PM
1class Solution {
2    int func(int i, int j, vector<vector<char>>& matrix,
3             vector<vector<int>>& dp) {
4        if (i < 0 || j < 0)
5            return 0;
6        if (matrix[i][j] == '0')
7            return 0;
8        if (dp[i][j] != -1)
9            return dp[i][j];
10        int top = func(i - 1, j, matrix, dp);
11        int left = func(i, j - 1, matrix, dp);
12        int diagonal = func(i - 1, j - 1, matrix, dp);
13        return dp[i][j] = 1 + min(top, min(left, diagonal));
14    }
15public:
16    int maximalSquare(vector<vector<char>>& matrix) {
17        int n = matrix.size();
18        int m = matrix[0].size();
19        vector<vector<int>> dp(n, vector<int>(m, -1));
20        int ans = 0;
21        for (int i = 0; i < n; i++) {
22            for (int j = 0; j < m; j++) {
23                if (matrix[i][j] == '1') {
24                    int side = func(i, j, matrix, dp);
25                    ans = max(ans, side * side);
26                }
27            }
28        }
29        return ans;
30    }
31};