// Last updated: 7/18/2026, 2:01:35 PM
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j])
                    height[j]++;
                else
                    height[j] = 0;
            }

            vector<int> cur = height;
            sort(cur.rbegin(), cur.rend());

            for (int j = 0; j < n; j++) {
                ans = max(ans, cur[j] * (j + 1));
            }
        }

        return ans;
    }
};