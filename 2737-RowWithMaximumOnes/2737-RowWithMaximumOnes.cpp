// Last updated: 7/18/2026, 2:00:15 PM
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxOnes = 0;
        int rowIndex = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) cnt++;
            }

            if (cnt > maxOnes) {
                maxOnes = cnt;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};