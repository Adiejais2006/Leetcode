// Last updated: 7/18/2026, 2:03:43 PM
class Solution {
    int bfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int cnt = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            cnt++;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++) {
                int nr = x + dx[k];
                int nc = y + dy[k];
                if (nr >= 0 && nr < grid.size() && nc >= 0 &&
                    nc < grid[0].size() && !vis[nr][nc] && grid[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return cnt;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans =0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int a = bfs(i, j, grid, vis);
                    ans = max(ans, a);
                }
            }
        }
        return ans;
    }
};