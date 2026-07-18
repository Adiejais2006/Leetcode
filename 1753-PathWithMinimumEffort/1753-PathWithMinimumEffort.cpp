// Last updated: 7/18/2026, 2:01:41 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
            int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> q;
        q.push({0, {0, 0}});
        vector<vector<int>> dist(n,vector<int>(m, 1e9));
        dist[0][0] = 0;
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;
            int dx[] = {-1, 0, 0, 1};
            int dy[] = {0, 1, -1, 0};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 &&
                    ny < m) {
                    int dif = max(d, abs(heights[x][y] - heights[nx][ny]));
                    if(dif < dist[nx][ny]){
                    q.push({dif, {nx, ny}});
                    dist[nx][ny] = dif;
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};