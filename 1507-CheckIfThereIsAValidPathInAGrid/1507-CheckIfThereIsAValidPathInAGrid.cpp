// Last updated: 7/18/2026, 2:01:57 PM
class Solution {
public:
    bool valida(int x, int y, int n, int m) {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int U = 0, D = 1, L = 2, R = 3;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{},     {L, R}, {U, D}, {L, D},
                                   {R, D}, {L, U}, {R, U}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;
        while (!q.empty()) {
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();if(x == n-1 && y == m-1) return true;
            int type = grid[x][y];
            for (auto i : dir[type]) {
                if (i == U) {
                    int dx = x - 1;
                    int dy = y;
                    if (valida(dx, dy, n, m)) {
                        int d = grid[dx][dy];
                        for (auto dii : dir[d]) {
                            if (dii == D && !vis[dx][dy]) {vis[dx][dy] = 1 ;
                                q.push({dx, dy});}
                        }
                    }
                };
                if (i == D) {
                    int dx = x + 1;
                    int dy = y;
                    if (valida(dx, dy, n, m)) {
                        int d = grid[dx][dy];
                        for (auto dii : dir[d]) {
                            if (dii == U && !vis[dx][dy]){ vis[dx][dy] = 1 ;
                                q.push({dx, dy});}
                        }
                    }
                };
                if (i == L) {
                    int dx = x;
                    int dy = y - 1;
                    if (valida(dx, dy, n, m)) {
                        int d = grid[dx][dy];
                        for (auto dii : dir[d]) {
                            if (dii == R && !vis[dx][dy]){ vis[dx][dy] = 1 ;
                                q.push({dx, dy});}
                        }
                    }
                };
                if (i == R) {
                    int dx = x;
                    int dy = y + 1;
                    if (valida(dx, dy, n, m)) {
                        int d = grid[dx][dy];
                        for (auto dii : dir[d]) {
                            if (dii == L && !vis[dx][dy]) {
                                vis[dx][dy] = 1;
                                q.push({dx, dy});
                            }
                        }
                    }
                };
            }
        }
        return false;
    }
};