// Last updated: 10/29/2026, 12:12:22 AM
1class Solution {
2
3public:
4    int calculateMinimumHP(vector<vector<int>>& dungeon) {
5        int m = dungeon.size();
6        int n = dungeon[0].size();
7        vector<vector<int>> dp(m, vector<int>(n, 0));
8        for (int i = m - 1; i >= 0; i--) {
9            for (int j = n - 1; j >= 0; j--) {
10                if (i == m - 1 && j == n - 1) {
11                    dp[i][j] = (dungeon[i][j] > 0) ? 1 : abs(dungeon[i][j]) + 1;
12                } else {
13                    int down = (i + 1 >= m) ? 1e9 : dp[i + 1][j];
14                    int right = (j + 1 >= n) ? 1e9 : dp[i][j + 1];
15
16                    int ans = min(down, right) - dungeon[i][j];
17                    dp[i][j] = (ans > 0) ? ans : 1;
18                }
19            }
20        }
21        return dp[0][0];
22    }
23};