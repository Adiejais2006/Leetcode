// Last updated: 7/18/2026, 2:02:11 PM
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m, 0), curr(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == 0) {
                    curr[j] = 0;
                }
                else if (i == 0 || j == 0) {
                    curr[j] = 1;
                }
                else {
                    curr[j] = 1 + min({
                        prev[j],      // up
                        curr[j - 1],  // left
                        prev[j - 1]   // diagonal
                    });
                }

                ans += curr[j];
            }

            prev = curr;
        }

        return ans;
    }
};