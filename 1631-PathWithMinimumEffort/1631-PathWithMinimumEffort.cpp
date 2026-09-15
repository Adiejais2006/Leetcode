// Last updated: 9/15/2026, 6:01:38 PM
1class Solution {
2public:
3    int minimumEffortPath(vector<vector<int>>& heights) {
4        int n = heights.size();
5        int m = heights[0].size();
6        vector<vector<int>> dist(n, vector<int>(m, 1e9));
7        dist[0][0] = 0;
8        priority_queue<pair<int, pair<int, int>>,
9                       vector<pair<int, pair<int, int>>>,
10                       greater<pair<int, pair<int, int>>>>
11            q;
12        q.push({0, {0, 0}});
13        while (!q.empty()) {
14            auto [diff, cord] = q.top();
15            q.pop();
16            int x = cord.first;
17            int y = cord.second;
18            int currentDiff = dist[x][y];
19            int dx[] = {-1, 1, 0, 0};
20            int dy[] = {0, 0, -1, 1};
21            for (int i = 0; i < 4; i++) {
22                int nx = x + dx[i];
23                int ny = y + dy[i];
24                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
25                    int newDiff = abs(heights[nx][ny] - heights[x][y]);
26                    int newEffort = max(currentDiff, newDiff);
27                    if (dist[nx][ny] > newEffort) {
28                        dist[nx][ny] = newEffort;
29                        q.push({dist[nx][ny], {nx, ny}});
30                    }
31                }
32            }
33        }
34        return dist[n - 1][m - 1];
35    }
36};