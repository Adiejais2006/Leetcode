// Last updated: 7/18/2026, 2:01:44 PM
class Solution {
public:
    int m, n;
    vector<vector<int>> visited;
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool dfs(int x, int y, int px, int py, char ch, vector<vector<char>>& grid) {
        if (visited[x][y]) return true;   // cycle found
        
        visited[x][y] = 1;
        
        for (auto& [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;
            
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == ch) {
                // skip parent cell
                if (nx == px && ny == py) continue;
                
                if (dfs(nx, ny, x, y, ch, grid))
                    return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j], grid))
                        return true;
                }
            }
        }
        
        return false;
    }
};