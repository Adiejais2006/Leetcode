// Last updated: 10/17/2026, 6:31:57 PM
int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); 
        if (m == 0) return 0; 
        int n = grid[0].size(); 
        
        vector<int> result (n + 1, INT_MAX);
        result[0] = 0;
     
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) 
                result[j + 1] = min(result[j], result[j + 1]) + grid[i][j];
            result[0] = result[1];
        }
        
        return result[n];
    }