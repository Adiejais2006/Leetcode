// Last updated: 10/29/2026, 6:12:32 PM
1class Solution {
2public:
3    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
7            return -1;
8        vector<vector<int>> vis(n, vector<int>(m, 0));
9        queue<pair<int, pair<int, int>>> q;
10        int ans = INT_MAX;
11        vis[0][0] = 1;
12        q.push({0, {0, 0}});
13        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
14        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
15        while (!q.empty()) {
16            auto [dist, it] = q.front();
17            q.pop();
18            int x = it.first;
19            int y = it.second;
20
21            if (x == n - 1 && y == m - 1)
22               ans=min(ans,dist+1);
23            for (int i = 0; i < 8; i++) {
24                int nx = x + dx[i];
25                int ny = y + dy[i];
26                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
27                    grid[nx][ny] == 0) {
28                    vis[nx][ny] = 1;
29                    q.push({dist + 1, {nx, ny}});
30                }
31            }
32        }
33        return ans==INT_MAX ? -1 : ans;
34    }
35};