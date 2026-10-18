// Last updated: 10/18/2026, 6:58:49 PM
1class Solution {
2public:
3    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        int i = 0;
7        int j = 0;
8        vector<vector<int>> vis(n, vector<int>(m, 0));
9        vis[0][0] =1 ;
10        while (i >= 0 && j >= 0 && i < n && j < m) {
11            int nx = i;
12            int ny = j;
13            if (grid[i][j] == 'R')
14                ny++;
15            else if (grid[i][j] == 'L')
16                ny--;
17            else if (grid[i][j] == 'U')
18                nx--;
19            else if (grid[i][j] == 'D')
20                nx++;
21
22            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) {
23                break;
24            }
25            vis[nx][ny] = 1;
26            i=nx;
27            j=ny;
28        }
29
30        return {i, j};
31    }
32};