// Last updated: 10/17/2026, 7:17:51 PM
1class Solution {
2public:
3    int minimumTotal(vector<vector<int>>& triangle) {
4        int n = triangle.size();
5        vector<vector<int>> dp = triangle;
6        for (int i = n - 2; i >= 0; i--) {
7            for (int j = 0; j <= i; j++) {
8                int down = dp[i + 1][j];
9                int downright = dp[i + 1][j + 1];
10
11                dp[i][j] = triangle[i][j] + min(down, downright);
12            }
13        }
14        return dp[0][0];
15    }
16};