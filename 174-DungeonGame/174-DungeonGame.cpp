// Last updated: 10/29/2026, 12:17:11 AM
1class Solution {
2public:
3    int calculateMinimumHP(vector<vector<int>>& dungeon) {
4        int m = dungeon.size();
5        int n = dungeon[0].size();
6        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
7        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
8        for (int i = m - 1; i >= 0; i--) {
9            for (int j = n - 1; j >= 0; j--) {
10                if (i == m - 1 && j == n - 1)
11                    continue;
12                int down = dp[i + 1][j];
13                int right = dp[i][j + 1];
14                int next = min(down, right);
15                dp[i][j] = max(1, next - dungeon[i][j]);
16            }
17        }
18        return dp[0][0];
19    }
20};