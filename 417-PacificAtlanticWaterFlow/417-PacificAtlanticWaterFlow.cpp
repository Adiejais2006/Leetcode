// Last updated: 10/29/2026, 5:33:39 PM
1class Solution {
2    void bfs(int i, int j, vector<vector<int>>& heights,
3             vector<vector<bool>>& vis) {
4        int n = heights.size();
5        int m = heights[0].size();
6        queue<pair<int, int>> q;
7        q.push({i, j});
8        vis[i][j] = 1;
9        int dx[] = {0, 0, -1, 1};
10        int dy[] = {-1, 1, 0, 0};
11        while (!q.empty()) {
12            auto [x, y] = q.front();
13            q.pop();
14            for (int i = 0; i < 4; i++) {
15                int nx = x + dx[i];
16                int ny = y + dy[i];
17                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
18                    heights[x][y] <= heights[nx][ny]) {
19                    vis[nx][ny] = 1;
20                    q.push({nx, ny});
21                }
22            }
23        }
24    }
25
26public:
27    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
28        int n = heights.size();
29        int m = heights[0].size();
30        vector<vector<bool>> pacific(n, vector<bool>(m, false));
31        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
32        for (int j = 0; j < m; j++)
33            bfs(0, j, heights, pacific);
34        for (int i = 0; i < n; i++)
35            bfs(i, 0, heights, pacific);
36        for (int j = 0; j < m; j++)
37            bfs(n - 1, j, heights, atlantic);
38        for (int i = 0; i < n; i++)
39            bfs(i, m - 1, heights, atlantic);
40        vector<vector<int>> ans;
41        for (int i = 0; i < n; i++) {
42            for (int j = 0; j < m; j++) {
43                if (pacific[i][j] && atlantic[i][j]) {
44                    ans.push_back({i, j});
45                }
46            }
47        }
48        return ans;
49    }
50};