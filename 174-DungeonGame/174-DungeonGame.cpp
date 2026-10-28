// Last updated: 10/29/2026, 12:00:03 AM
1class Solution {
2    int func(int i, int j, vector<vector<int>>& dungeon,
3             vector<vector<int>>& dp) {
4        int n = dungeon.size();
5        int m = dungeon[0].size();
6        if (i >= n || j >= m)
7            return 1e9;
8        if (i == n - 1 && j == m - 1)
9            return max(1, 1 - dungeon[i][j]);
10        if (dp[i][j] != -1)
11            return dp[i][j];
12        int right = func(i, j + 1, dungeon, dp);
13        int down = func(i + 1, j, dungeon, dp);
14        int next = min(right, down);
15        return dp[i][j] = max(1, next - dungeon[i][j]);
16    }
17
18public:
19    int calculateMinimumHP(vector<vector<int>>& dungeon) {
20        int n = dungeon.size();
21        int m = dungeon[0].size();
22        vector<vector<int>> dp(n, vector<int>(m, -1));
23        return func(0, 0, dungeon, dp);
24    }
25};