// Last updated: 11/15/2026, 3:52:52 PM
1class Solution {
2    void bfs(int i, int j, vector<vector<int>>& grid,
3             queue<pair<pair<int, int>, int>>& q) {
4        int n = grid.size();
5        int m = grid[0].size();
6        queue<pair<int, int>> temp;
7        temp.push({i, j});
8        q.push({{i, j}, 0});
9        grid[i][j] = 2;
10        int dx[] = {-1, 1, 0, 0};
11        int dy[] = {0, 0, -1, 1};
12        while (!temp.empty()) {
13            auto [x, y] = temp.front();
14            temp.pop();
15            for (int k = 0; k < 4; k++) {
16                int nx = x + dx[k];
17                int ny = y + dy[k];
18                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
19                    grid[nx][ny] == 1) {
20
21                    grid[nx][ny] = 2;
22                    temp.push({nx, ny});
23                    q.push({{nx, ny}, 0});
24                }
25            }
26        }
27    }
28public:
29    int shortestBridge(vector<vector<int>>& grid) {
30        int n = grid.size();
31        int m = grid[0].size();
32        queue<pair<pair<int, int>, int>> q;
33        bool found = false;
34        for (int i = 0; i < n && !found; i++) {
35            for (int j = 0; j < m; j++) {
36                if (grid[i][j] == 1) {
37                    bfs(i, j, grid, q);
38                    found = true;
39                    break;
40                }
41            }
42        }
43        int dx[] = {-1, 1, 0, 0};
44        int dy[] = {0, 0, -1, 1};
45        while (!q.empty()) {
46            auto [pos, dist] = q.front();
47            q.pop();
48            auto [x, y] = pos;
49            for (int k = 0; k < 4; k++) {
50                int nx = x + dx[k];
51                int ny = y + dy[k];
52                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
53                    if (grid[nx][ny] == 1)
54                        return dist;
55                    if (grid[nx][ny] == 0) {
56                        grid[nx][ny] = 2;
57                        q.push({{nx, ny}, dist + 1});
58                    }
59                }
60            }
61        }
62        return -1;
63    }
64};