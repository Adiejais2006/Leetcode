// Last updated: 7/18/2026, 2:00:01 PM
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        // queue me hamne saare thieves ki locatiin daal di hai taaki usse min manhataaan distance aie safeness calculate kr sake to dit array ek tarah se safeness of every element i arrau hai 
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for (int k = 0; k < 4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (i >= 0 && i < n && j >= 0 && j < n &&
                    dist[i][j] == INT_MAX) {
                    dist[i][j] = dist[x][y] + 1;
                    q.push({i, j});
                }
            }
        }
        int ans = INT_MIN;
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({dist[0][0], {0, 0}});
        vector<vector<int>> best(n, vector<int>(n, -1));
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int safem = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if (x == n - 1 && y == n - 1)
                return safem;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for (int k = 0; k < 4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (i >= 0 && i < n && j >= 0 && j < n) {
                    int candidate = min(safem, dist[i][j]);

                    if (candidate > best[i][j]) {
                        best[i][j] = candidate;
                        pq.push({candidate, {i, j}});
                    }
                }
            }
        }
        return 0;
    }
};