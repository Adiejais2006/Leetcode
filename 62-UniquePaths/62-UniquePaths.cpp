// Last updated: 9/25/2026, 5:06:14 PM
1class Solution {
2public:
3    int uniquePaths(int m, int n) {
4        vector<vector<int>> dp(m, vector<int>(n, 1));
5
6
7        for(int i = 1 ; i< m ; i++){
8            for(int j =  1 ; j < n ; j++){
9
10                dp[i][j] = dp[i-1][j] + dp[i][j-1];
11            }
12        }
13        return dp[m-1][n-1];
14    }
15};