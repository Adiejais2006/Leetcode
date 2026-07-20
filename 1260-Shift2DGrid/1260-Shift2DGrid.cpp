// Last updated: 7/20/2026, 9:32:40 PM
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int total = m * n;
7        k %= total;
8        vector<vector<int>> ans(m, vector<int>(n));
9        for (int i = 0; i < m; i++) {
10            for (int j = 0; j < n; j++) {
11                int oldIndex = i * n + j;
12                int newIndex = (oldIndex + k) % total;
13                int newRow = newIndex / n;
14                int newCol = newIndex % n;
15                ans[newRow][newCol] = grid[i][j];
16            }
17        }
18
19        return ans;
20    }
21};