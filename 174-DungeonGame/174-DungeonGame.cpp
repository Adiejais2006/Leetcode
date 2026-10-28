// Last updated: 10/28/2026, 11:58:38 PM
1class Solution {
2    int func(int i, int j, vector<vector<int>>& dungeon,
3             vector<vector<int>>& dp) {
4
5        int n = dungeon.size();
6        int m = dungeon[0].size();
7
8        if (i >= n || j >= m)
9            return 1e9;
10
11        if (i == n - 1 && j == m - 1)
12            return max(1, 1 - dungeon[i][j]);
13
14        if (dp[i][j] != -1)
15            return dp[i][j];
16
17        int right = func(i, j + 1, dungeon, dp);
18        int down = func(i + 1, j, dungeon, dp);
19
20        int next = min(right, down);
21
22        return dp[i][j] = max(1, next - dungeon[i][j]);
23    }
24
25public:
26    int calculateMinimumHP(vector<vector<int>>& dungeon) {
27        int n = dungeon.size();
28        int m = dungeon[0].size();
29
30        vector<vector<int>> dp(n, vector<int>(m, -1));
31
32        return func(0, 0, dungeon, dp);
33    }
34};