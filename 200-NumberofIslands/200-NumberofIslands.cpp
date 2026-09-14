// Last updated: 9/14/2026, 1:42:55 PM
1class Solution {
2    void bfs(int i, int j, vector<vector<char>>& grid) {
3        queue<pair<int, int>> q;
4        q.push({i, j});
5        int dx[] = {-1, 1, 0, 0};
6        int dy[] = {0, 0, 1, -1};
7        while (!q.empty()) {
8            auto it = q.front();
9            q.pop();
10            int x = it.first;
11            int y = it.second;
12            for (int i = 0; i < 4; i++) {
13                int nx = x + dx[i];
14                int ny = y + dy[i];
15                if (nx >= 0 && nx < grid.size() && ny >= 0 &&
16                    ny < grid[0].size() && grid[nx][ny] == '1') {
17                    grid[nx][ny] = '0';
18                    q.push({nx, ny});
19                }
20            }
21        }
22    }
23
24public:
25    int numIslands(vector<vector<char>>& grid) {
26        int n = grid.size();
27        int cnt = 0;
28        int m = grid[0].size();
29        for (int i = 0; i < n; i++) {
30            for (int j = 0; j < m; j++) {
31                if (grid[i][j] == '1') {
32                    bfs(i, j, grid);
33                    cnt++;
34                }
35            }
36        }
37        return cnt;
38    }
39};