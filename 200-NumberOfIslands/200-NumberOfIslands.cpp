// Last updated: 7/18/2026, 2:05:41 PM
class Solution {
    void bfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < grid.size() && ny >= 0 &&
                    ny < grid[0].size() && grid[nx][ny] == '1' &&
                    !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!vis[i][j] && grid[i][j] == '1') {

                    bfs(i, j, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};