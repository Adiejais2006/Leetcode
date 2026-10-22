// Last updated: 10/22/2026, 4:03:40 PM
1class Solution {
2
3public:
4    int maximalSquare(vector<vector<char>>& matrix) {
5        int n = matrix.size();
6        int m = matrix[0].size();
7        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
8        int ans = 0;
9        for (int i = 1; i <= n; i++) {
10            for (int j = 1; j <= m; j++) {
11                if (matrix[i - 1][j - 1] == '1') {
12                    int top = dp[i - 1][j];
13                    int left = dp[i][j - 1];
14                    int diagonal = dp[i - 1][j - 1];
15                    dp[i][j] = 1 + min(top, min(left, diagonal));
16                    ans = max(ans, dp[i][j]);
17                }
18            }
19        }
20        return ans*ans;
21    }
22};