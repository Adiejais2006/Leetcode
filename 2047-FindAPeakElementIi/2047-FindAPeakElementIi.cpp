// Last updated: 7/18/2026, 2:01:20 PM
class Solution { int maxele(vector<vector<int>>& mat, int row) {
        int max = -1;
        int index = 0;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][row] > max) {
                max = mat[i][row];
                index = i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
           int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = maxele(mat, mid);
            int left = mid - 1 >= 0 ? mat[row][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? mat[row][mid + 1] : INT_MIN;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row,mid};
            } else if (mat[row][mid] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};