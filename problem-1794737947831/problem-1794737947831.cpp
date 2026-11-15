// Last updated: 11/15/2026, 3:49:07 PM
1class Solution {
2    void bfs(int i, int j, vector<vector<int>>& grid,
3             queue<pair<int, int>>& q) {
4        int n = grid.size();
5        int m = grid[0].size();
6        queue<pair<int, int>> temp;
7        temp.push({i, j});
8        q.push({i, j});
9        grid[i][j] = 2;
10        int dx[] = {-1, 1, 0, 0};
11        int dy[] = {0, 0, -1, 1};
12        while (!temp.empty()) {
13            auto [x, y] = temp.front();
14            temp.pop();
15            for (int k = 0; k < 4; k++) {
16                int nx = x + dx[k];
17                int ny = y + dy[k];
18                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
19                    grid[nx][ny] == 1) {
20                    grid[nx][ny] = 2;
21                    q.push({nx, ny});
22                    temp.push({nx, ny});
23                }
24            }
25        }
26    }
27
28public:
29    int shortestBridge(vector<vector<int>>& grid) {
30        int n = grid.size();
31        int m = grid[0].size();
32        queue<pair<int, int>> q;
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
45        int ans = 0;
46        while (!q.empty()) {
47            int sz = q.size(); 
48            while (sz--) {
49                auto [x, y] = q.front();
50                q.pop();
51                for (int k = 0; k < 4; k++) {
52                    int nx = x + dx[k];
53                    int ny = y + dy[k];
54                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
55                        if (grid[nx][ny] == 1)
56                            return ans;
57                        if (grid[nx][ny] == 0) {
58                            grid[nx][ny] = 2;
59                            q.push({nx, ny});
60                        }
61                    }
62                }
63            }
64            ans++;
65        }
66        return ans;
67    }
68};