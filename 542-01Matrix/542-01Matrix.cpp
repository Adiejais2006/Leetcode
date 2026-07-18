// Last updated: 7/18/2026, 2:04:05 PM
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int,int>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for (int k = 0; k < 4; k++) {
                int nrow = x + delRow[k];
                int ncol = y + delCol[k];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    dist[nrow][ncol] == -1) {
                         dist[nrow][ncol] = dist[x][y] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return dist;
    }
};