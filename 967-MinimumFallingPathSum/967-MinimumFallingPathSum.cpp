// Last updated: 7/18/2026, 2:02:59 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 1e9;
        vector<int> prev(m, 0);
        for (int i = 0; i < m; i++) {
            prev[i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            vector<int>temp(m,0);
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + prev[j];
                int upleft = matrix[i][j] + ((j > 0) ? prev[j - 1] : 1e9);
                int upright = matrix[i][j] + ((j < m - 1) ? prev[j + 1] : 1e9);
               temp[j] = min(up, min(upleft, upright));
            }
            prev=temp;
        }

        for (int i = 0; i < m; i++) {
            ans = min(ans, prev[i]);
        }

        return ans;
    }
};