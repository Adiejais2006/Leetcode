// Last updated: 7/18/2026, 2:06:11 PM
class Solution {
public:
    void solve(vector<vector<char>>& mat) {
           int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            if (mat[0][i] == 'O') {
                vis[0][i] = 1;
                q.push({0, i});
            }
        }
        // bottom row
        for (int i = 0; i < m; i++) {
            if (mat[n - 1][i] == 'O') {
                vis[n - 1][i] = 1;
                q.push({n - 1, i});
            }
        }
        // right column
        for (int i = 0; i < n; i++) {
            if (mat[i][m - 1] == 'O') {
                vis[i][m - 1] = 1;
                q.push({i, m - 1});
            }
        }
        // left column
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 'O') {
                vis[i][0] = 1;
                q.push({i, 0});
            }
        }

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            int dx[] = {-1, 0, 0, 1};
            int dy[] = {0, 1, -1, 0};
            for (int k = 0; k < 4; k++) {
                int ni = x + dx[k];
                int nj = y + dy[k];
                if (ni >= 0 && ni < mat.size() && nj >= 0 &&
                    nj < mat[0].size()) {
                    if (mat[ni][nj] == 'O' && !vis[ni][nj]) {
                        vis[ni][nj] = 1;
                        q.push({ni, nj});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O' && !vis[i][j]) mat[i][j] = 'X';
            }
        }
       
    }
};