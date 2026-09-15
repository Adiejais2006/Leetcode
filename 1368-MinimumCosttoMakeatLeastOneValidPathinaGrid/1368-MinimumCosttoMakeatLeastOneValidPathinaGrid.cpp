// Last updated: 9/15/2026, 10:02:32 PM
1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        vector<vector<int>> dist(n, vector<int>(m, 1e9));
7        dist[0][0] = 0;
8        int dx[4] = {0, 0, 1, -1};
9        int dy[4] = {1, -1, 0, 0};
10        deque<pair<int, int>> dq;
11        dq.push_front({0, 0});
12        while (!dq.empty()) {
13            auto [x, y] = dq.front();
14            dq.pop_front();
15            for (int i = 0; i < 4; i++) {
16                int nx = x + dx[i];
17                int ny = y + dy[i];
18                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
19                    int cost = dist[x][y] + (grid[x][y] == i + 1 ? 0 : 1);
20                    if (cost < dist[nx][ny]) {
21                        dist[nx][ny] = cost;
22                        if (grid[nx][ny] == i + 1) {
23                            dq.push_front({nx, ny});
24                        } else
25                            dq.push_back({nx, ny});
26                    }
27                }
28            }
29        }
30        return dist[n-1][m-1];
31    }
32};