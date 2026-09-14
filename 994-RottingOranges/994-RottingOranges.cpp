// Last updated: 9/14/2026, 2:11:45 PM
1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        int time = INT_MIN;
7        queue<pair<int, pair<int, int>>> q;
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                if (grid[i][j] == 2)
11                    q.push({0, {i, j}});
12            }
13        }
14        while (!q.empty()) {
15            auto it = q.front();
16            q.pop();
17            int t = it.first;
18            int x = it.second.first;
19            int y = it.second.second;
20            time = max(time, t);
21            int dx[] = {-1, 1, 0, 0};
22            int dy[] = {0, 0, -1, 1};
23            for (int k = 0; k < 4; k++) {
24                int nx = x + dx[k];
25                int ny = y + dy[k];
26
27                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
28                    grid[nx][ny] == 1) {
29                    grid[nx][ny] = 2;
30                    q.push({t + 1, {nx, ny}});
31                }
32            }
33        }
34        for (int i = 0; i < n; i++) {
35            for (int j = 0; j < m; j++) {
36                if (grid[i][j] == 1)
37                    return -1;
38            }
39        }
40        return max(time, 0);
41    }
42};