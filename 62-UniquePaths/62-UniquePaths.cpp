// Last updated: 7/18/2026, 2:07:07 PM
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        prev[0] = 1;
        for (int i = 0; i < m; i++) {
            vector<int> temp(n,0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] =1;
                    continue;
                }
                int up = prev[j];
               int left = (j > 0) ? temp[j - 1] : 0;
               temp[j] = up + left;
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};