// Last updated: 9/14/2026, 1:41:13 PM
1class Solution {
2    void bfs(int i, int j, vector<vector<int>>& vis,
3             vector<vector<char>>& grid) {
4        queue<pair<int, int>> q;
5        q.push({i, j});
6        vis[i][j] = 1;
7        int dx[] = {-1, 1, 0, 0};
8        int dy[] = {0, 0, 1, -1};
9        while (!q.empty()) {
10            auto it = q.front();
11            q.pop();
12            int x = it.first;
13            int y = it.second;
14            for (int i = 0; i < 4; i++) {
15                int nx = x + dx[i];
16                int ny = y + dy[i];
17                if (nx >= 0 && nx < vis.size() && ny >= 0 &&
18                    ny < vis[0].size() && !vis[nx][ny] && grid[nx][ny]=='1') {
19                    vis[nx][ny] = 1;
20                    q.push({nx, ny});
21                }
22            }
23        }
24    }
25
26public:
27    int numIslands(vector<vector<char>>& grid) {
28        int n = grid.size();
29        int cnt = 0;
30        int m = grid[0].size();
31        vector<vector<int>> vis(n, vector<int>(m, 0));
32        for (int i = 0; i < n; i++) {
33            for (int j = 0; j < m; j++) {
34                if (!vis[i][j] && grid[i][j]=='1') {
35                    bfs(i, j, vis, grid);
36                    cnt++;
37                }
38            }
39        }
40        return cnt;
41    }
42};