// Last updated: 7/18/2026, 2:02:44 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, pair<int, int>>> q;
        // time x and y
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({0, {i, j}});
            }
        }
        int ans = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int time = it.first;
            ans = max(ans,time);
            int x = it.second.first;
            int y = it.second.second;
            int dx[] = {-1, 0, 0, 1};
            int dy[] = {0, 1, -1, 0};
            for (int i = 0; i < 4; i++) {
                int nr = x + dx[i];
                int nc = y + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                  if(grid[nr][nc]==1){
                    grid[nr][nc] = 2 ; 
                    q.push({time+1 ,{nr,nc}});
                  }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1 ;
            }
        }

        // if(ans==INT_MIN) return -1 ;
        return ans ;
    }
};