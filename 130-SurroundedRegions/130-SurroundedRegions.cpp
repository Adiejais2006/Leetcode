// Last updated: 10/29/2026, 4:05:11 PM
1class Solution {
2public:
3    void solve(vector<vector<char>>& board) {
4        int n = board.size();
5        int m = board[0].size();
6        vector<vector<int>> vis(n, vector<int>(m, 0));
7        queue<pair<int, int>> q;
8        int dx[] = {0, 0, -1, 1};
9        int dy[] = {-1, 1, 0, 0};
10        for (int i = 0; i < n; i++) {
11            if (board[i][0] == 'O') {
12                vis[i][0] = 1;
13                q.push({i, 0});
14            }
15        }
16        for (int i = 0; i < n; i++) {
17            if (board[i][m - 1] == 'O') {
18                vis[i][m - 1] = 1;
19                q.push({i, m - 1});
20            }
21        }
22        for (int i = 0; i < m; i++) {
23            if (board[0][i] == 'O') {
24                vis[0][i] = 1;
25                q.push({0, i});
26            }
27        }
28        for (int i = 0; i < m; i++) {
29            if (board[n - 1][i] == 'O') {
30                vis[n - 1][i] = 1;
31                q.push({n - 1, i});
32            }
33        }
34        while (!q.empty()) {
35            auto [x, y] = q.front();
36            q.pop();
37            for (int i = 0; i < 4; i++) {
38                int nx = x + dx[i];
39                int ny = y + dy[i];
40                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
41                    board[nx][ny] == 'O') {
42                    vis[nx][ny] = 1;
43                    q.push({nx, ny});
44                }
45            }
46        }
47        for (int i = 0; i < n; i++) {
48            for (int j = 0; j < m; j++) {
49                if (!vis[i][j] && board[i][j] == 'O')
50                    board[i][j] = 'X';
51            }
52        }
53    }
54};