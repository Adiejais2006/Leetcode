// Last updated: 7/18/2026, 2:02:40 PM
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        // top row
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                vis[0][i] = 1;
                q.push({0, i});
            }
        }
        // bottom row
        for (int i = 0; i < m; i++) {
            if (grid[n - 1][i] == 1) {
                vis[n - 1][i] = 1;
                q.push({n - 1, i});
            }
        }
        // left col
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                vis[i][0] = 1;
                q.push({i, 0});
            }
        }
        // right col
        for (int i = 0; i < n; i++) {
            if (grid[i][m - 1] == 1) {
                vis[i][m - 1] = 1;
                q.push({i, m - 1});
            }
        }
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
           

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (!vis[nx][ny] && grid[nx][ny] == 1) {
                     
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1  && !vis[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};