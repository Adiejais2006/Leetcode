// Last updated: 10/26/2026, 12:10:47 PM
1class Solution {
2    int bfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid,
3            int k) {
4        int n = grid.size();
5        int m = grid[0].size();
6        vis[i][j] = 1;
7        queue<pair<int, int>> q;
8        q.push({i, j});
9        int cnt = 0;
10        long long sum = 0;
11        int dx[] = {-1, 0, 1, 0};
12        int dy [] = {0, 1, 0, -1};
13        while (!q.empty()) {
14            auto [x, y] = q.front();
15            q.pop();
16            sum += grid[x][y];
17            for (int i = 0; i < 4; i++) {
18                int ni = x + dx[i];
19                int nj = y + dy[i];
20                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] &&
21                    grid[ni][nj] != 0 ){
22                        vis[ni][nj]=1;
23                        q.push({ni,nj});
24                    }
25            }
26        }
27        if(sum%k==0) cnt++;
28        return cnt;
29    }
30
31public:
32    int countIslands(vector<vector<int>>& grid, int k) {
33        int n = grid.size();
34        int m = grid[0].size();
35        vector<vector<int>> vis(n, vector<int>(m, 0));
36        int cnt = 0;
37        for (int i = 0; i < n; i++) {
38            for (int j = 0; j < m; j++) {
39                if (!vis[i][j] && grid[i][j] != 0) {
40                    cnt += bfs(i, j, vis, grid, k);
41                }
42            }
43        }
44        return cnt;
45    }
46};