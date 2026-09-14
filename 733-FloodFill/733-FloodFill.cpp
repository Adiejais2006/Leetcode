// Last updated: 9/14/2026, 2:21:40 PM
1class Solution {
2public:
3    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
4                                  int color) {
5        int n = image.size();
6        int m = image[0].size();
7        int origcolor = image[sr][sc];
8        if(origcolor==color)return image;
9        queue<pair<int, int>> q;
10        image[sr][sc] = color;
11        q.push({sr, sc});
12        while (!q.empty()) {
13            auto [x, y] = q.front();
14            q.pop();
15            int dx[] = {-1, 1, 0, 0};
16            int dy[] = {0, 0, -1, 1};
17            for (int k = 0; k < 4; k++) {
18                int nx = x + dx[k];
19                int ny = y + dy[k];
20                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
21                    image[nx][ny] == origcolor) {
22                    image[nx][ny] = color;
23                    q.push({nx, ny});
24                }
25            }
26        }
27        return image;
28    }
29};