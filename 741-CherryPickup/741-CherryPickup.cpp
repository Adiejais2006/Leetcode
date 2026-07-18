// Last updated: 7/18/2026, 2:03:31 PM
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, dp(0, 0, 0, grid, memo, n));
    }

private:
    int dp(int r1, int c1, int r2, vector<vector<int>>& grid, vector<vector<vector<int>>>& memo, int n) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;
        if (r1 == n - 1 && c1 == n - 1) return grid[r1][c1];
        if (memo[r1][c1][r2] != -1) return memo[r1][c1][r2];
        
        int res = grid[r1][c1];
        if (r1 != r2 || c1 != c2) res += grid[r2][c2];
        
        int next = max({dp(r1 + 1, c1, r2 + 1, grid, memo, n),
                        dp(r1 + 1, c1, r2, grid, memo, n),
                        dp(r1, c1 + 1, r2 + 1, grid, memo, n),
                        dp(r1, c1 + 1, r2, grid, memo, n)});
        
        return memo[r1][c1][r2] = res + next;
    }
};