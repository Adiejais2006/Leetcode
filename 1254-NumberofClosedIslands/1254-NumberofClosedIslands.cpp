// Last updated: 10/25/2026, 2:28:18 PM
1class Solution {
2    bool bfs(int i, int j, vector<vector<int>>& vis,
3             vector<vector<int>>& grid) {
4        vis[i][j] = 1;
5        queue<pair<int, int>> q;
6        q.push({i, j});
7        int dx[] = {-1, 0, 1, 0};
8        int dy[] = {0, 1, 0, -1};
9        bool isClosed = true;
10        while (!q.empty()) {
11            auto [x, y] = q.front();
12            q.pop();
13            for (int i = 0; i < 4; i++) {
14                int nx = x + dx[i];
15                int ny = y + dy[i];
16                if (x == 0 || x == vis.size() - 1 || y == 0 ||
17                    y == vis[0].size() - 1)
18                    isClosed = false;
19                if (nx >= 0 && nx < vis.size() && ny >= 0 &&
20                    ny < vis[0].size() && grid[nx][ny] == 0 && !vis[nx][ny]) {
21                    vis[nx][ny] = 1;
22                    q.push({nx, ny});
23                }
24            }
25        }
26        return isClosed;
27    }
28
29public:
30    int closedIsland(vector<vector<int>>& grid) {
31        int n = grid.size();
32        int m = grid[0].size();
33        int ans = 0;
34        vector<vector<int>> vis(n, vector<int>(m, 0));
35        for (int i = 0; i <= n - 1; i++) {
36            for (int j = 0; j <= m - 1; j++) {
37                if (grid[i][j] == 0 && !vis[i][j]) {
38                    if (bfs(i, j, vis, grid))
39
40                        ans++;
41                }
42            }
43        }
44        return ans;
45    }
46};