// Last updated: 10/31/2026, 2:40:15 PM
1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        int n = mat.size();
5        int m = mat[0].size();
6        vector<vector<int>> ans(n, vector<int>(m, -1));
7        queue<pair<int, int>> q;
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                if (mat[i][j] == 0) {
11                    q.push({i, j});
12                    ans[i][j] = 0;
13                }
14            }
15        }
16        int dx[] = {0, 0, -1, 1};
17        int dy[] = {-1, 1, 0, 0};
18        while (!q.empty()) {
19            auto [x, y] = q.front();
20            q.pop();
21            for (int i = 0; i < 4; i++) {
22                int nx = x + dx[i];
23                int ny = y + dy[i];
24                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
25                    ans[nx][ny] == -1) {
26                    ans[nx][ny] = ans[x][y] + 1;
27                   q.push({nx,ny});
28                }
29            }
30        }
31        return ans;
32    }
33};