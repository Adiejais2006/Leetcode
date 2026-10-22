// Last updated: 10/22/2026, 3:55:08 PM
1class Solution {
2    int func(int i, int j, vector<vector<char>>& matrix,
3             vector<vector<int>>& dp) {
4        if (i < 0 || j < 0)
5            return 0;
6
7        if (matrix[i][j] == '0')
8            return 0;
9
10        if (dp[i][j] != -1)
11            return dp[i][j];
12
13        int top = func(i - 1, j, matrix, dp);
14        int left = func(i, j - 1, matrix, dp);
15        int diagonal = func(i - 1, j - 1, matrix, dp);
16
17        return dp[i][j] = 1 + min(top, min(left, diagonal));
18    }
19
20public:
21    int maximalSquare(vector<vector<char>>& matrix) {
22        int n = matrix.size();
23        int m = matrix[0].size();
24
25        vector<vector<int>> dp(n, vector<int>(m, -1));
26        int ans = 0;
27
28        for (int i = 0; i < n; i++) {
29            for (int j = 0; j < m; j++) {
30                if (matrix[i][j] == '1') {
31                    int side = func(i, j, matrix, dp);
32                    ans = max(ans, side * side);
33                }
34            }
35        }
36
37        return ans;
38    }
39};