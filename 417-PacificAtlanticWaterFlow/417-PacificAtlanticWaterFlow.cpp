// Last updated: 11/18/2026, 2:30:30 PM
1class Solution {
2    void bfs(int x, int y, vector<vector<int>>& heights,
3             vector<vector<bool>>& vis) {
4        int n = heights.size();
5        int m = heights[0].size();
6        queue<pair<int, int>> q;
7        q.push({x, y});
8        vis[x][y] = 1;
9        int dx[] = {0, 0, -1, 1};
10        int dy[] = {-1, 1, 0, 0};
11        while (!q.empty()) {
12            auto [i, j] = q.front();
13            q.pop();
14    
15            for (int k = 0; k < 4; k++) {
16                int ni = i + +dx[k];
17                int nj = j + dy[k];
18                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
19                    heights[ni][nj] >= heights[i][j] && !vis[ni][nj]) {
20                    vis[ni][nj] = 1;
21                    q.push({ni, nj});
22                }
23            }
24        }
25    }
26
27public:
28    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
29        int n = heights.size();
30        int m = heights[0].size();
31        vector<vector<bool>> pacific(n, vector<bool>(m, false));
32        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
33        vector<vector<int>> ans;
34        for (int i = 0; i < n; i++) {
35            bfs(i,0, heights, pacific);
36        }
37        for (int i = 0; i < n; i++) {
38            bfs(i,m-1, heights, atlantic);
39        }
40        for (int j = 0; j < m; j++) {
41            bfs(0,j, heights,pacific);
42        }
43        for (int j = 0; j < m; j++) {
44            bfs(n-1,j, heights,atlantic);
45        }
46        for (int i = 0; i < n; i++) {
47            for (int j = 0; j < m; j++) {
48                if (atlantic[i][j] && pacific[i][j]) {
49                    ans.push_back({i, j});
50                }
51            }
52        }
53        return ans;
54    }
55};