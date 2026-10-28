// Last updated: 10/28/2026, 6:58:53 PM
1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        queue<pair<int, pair<int, int>>> q;
7        for (int i = 0; i < n; i++) {
8            for (int j = 0; j < m; j++) {
9                if (grid[i][j] == 2)
10                    if (grid[i][j] == 2)
11                        q.push({0, {i, j}});
12            }
13        }
14        int ans = 0;
15        int dx[] = {0, 0, -1, 1};
16        int dy[] = {-1, 1, 0, 0};
17        while (!q.empty()) {
18            auto [time, cords] = q.front();
19            int x = cords.first;
20            int y = cords.second;
21            q.pop();
22            ans = max(ans, time);
23            for (int i = 0; i < 4; i++) {
24                int nx = x + dx[i];
25                int ny = y + dy[i];
26                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
27                    grid[nx][ny] = 2;
28                    q.push({time + 1, {nx, ny}});
29                }
30            }
31        }
32        for (int i = 0; i < n; i++) {
33            for (int j = 0; j < m; j++) {
34                if (grid[i][j] == 1)
35                    return -1;
36            }
37        }
38        return ans;
39    }
40};