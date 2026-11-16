// Last updated: 11/16/2026, 6:02:58 PM
1class Solution {
2public:
3    int numSubmat(vector<vector<int>>& mat) {
4         int n = mat.size(), m = mat[0].size();
5        vector<vector<int>> dp(n, vector<int>(m, 0));
6        for (int i = 0; i < n; i++) {
7            for (int j = 0; j < m; j++) {
8                if (mat[i][j] == 1) {
9                    dp[i][j] = 1 + (j > 0 ? dp[i][j - 1] : 0);
10                }
11            }
12        }
13        int ans = 0;
14        for (int i = 0; i < n; i++) {
15            for (int j = 0; j < m; j++) {
16                int width = INT_MAX;
17                for (int k = i; k >= 0; k--) {
18                    width = min(width, dp[k][j]);
19                    if (width == 0) break;
20                    ans += width;
21                }
22            }
23        }
24        return ans;
25    }
26};