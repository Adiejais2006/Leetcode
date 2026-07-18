// Last updated: 7/18/2026, 2:03:34 PM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int n = image.size();
        int m = image[0].size();
        // vector<vector<int>> ans = grid;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int initialColor = image[sr][sc];
        image[sr][sc] = newColor;
        vis[sr][sc] = 1;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            int dx[] = {-1, 0, 0, 1};
            int dy[] = {0, 1, -1, 0};
            for (int i = 0; i < 4; i++) {
                int nr = x + dx[i];
                int nc = y + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (image[nr][nc] == initialColor && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                        image[nr][nc] = newColor;
                    }
                }
            }
        }
        return image; 
    }
};