// Last updated: 10/29/2026, 6:17:49 PM
1class Solution {
2public:
3    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
7            return -1;
8        vector<vector<int>> vis(n, vector<int>(m, 0));
9        queue<pair<int, pair<int, int>>> q;
10        q.push({1, {0, 0}});
11        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
12        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
13        int ans = INT_MAX;
14        while (!q.empty()) {
15            auto [dist, it] = q.front();
16            q.pop();
17            int x = it.first;
18            int y = it.second;
19            if (x == n - 1 && y == m - 1)
20                ans = min(ans, dist);
21
22            for (int i = 0; i < 8; i++) {
23                int nx = x + dx[i];
24                int ny = y + dy[i];
25                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
26                    grid[nx][ny] == 0 && !vis[nx][ny]) {
27                    vis[nx][ny] = 1;
28                    q.push({dist + 1, {nx, ny}});
29                }
30            }
31        }
32        return ans==INT_MAX ? -1 : ans ;
33    }
34};