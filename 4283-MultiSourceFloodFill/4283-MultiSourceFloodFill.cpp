// Last updated: 7/18/2026, 1:58:48 PM
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> vis(n, vector<int>(m, -1));
        vector<vector<int>> grid(n, vector<int>(m, 0));

        queue<pair<int,int>> q;

        for (int i = 0; i < sources.size(); i++) {
            int row = sources[i][0];
            int col = sources[i][1];
            int color = sources[i][2];

            grid[row][col] = color;
            vis[row][col] = 0;

            q.push({row, col});
        }

        int time = 0;

        while (!q.empty()) {

            int sz = q.size();

            int dr[4] = {0, 0, 1, -1};
            int dc[4] = {1, -1, 0, 0};

            time++;

            for (int i = 0; i < sz; i++) {

                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                int color = grid[row][col];

                for (int j = 0; j < 4; j++) {

                    int nrow = row + dr[j];
                    int ncol = col + dc[j];

                    if (nrow >= 0 && ncol >= 0 &&
                        nrow < n && ncol < m) {

                        if (vis[nrow][ncol] == -1) {

                            grid[nrow][ncol] = color;
                            vis[nrow][ncol] = time;
                            q.push({nrow, ncol});
                        }
                        else if (vis[nrow][ncol] == time) {

                            grid[nrow][ncol] =
                                max(grid[nrow][ncol], color);
                        }
                    }
                }
            }
        }

        return grid;
    }
};