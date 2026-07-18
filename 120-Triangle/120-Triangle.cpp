// Last updated: 7/18/2026, 2:06:22 PM
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<int> prev(m);
        for (int i = 0; i < triangle[n - 1].size(); i++) {
            prev[i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            vector<int> cur(triangle[i].size(), 0);
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + prev[j];
                int downRight = triangle[i][j] + prev[j + 1];
                cur[j] = min(down, downRight);
            }
            prev=cur;
        }

        return prev[0];
    }
};