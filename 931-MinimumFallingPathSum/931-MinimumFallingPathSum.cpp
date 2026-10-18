// Last updated: 10/18/2026, 2:16:58 PM
1class Solution {
2public:
3    int minFallingPathSum(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        int m = matrix[0].size();
6        int ans = 1e9;
7        vector<int> prev(m, 0);
8        for (int i = 0; i < m; i++) {
9            prev[i] = matrix[0][i];
10        }
11        for (int i = 1; i < n; i++) {
12            vector<int>temp(m,0);
13            for (int j = 0; j < m; j++) {
14                int up = matrix[i][j] + prev[j];
15                int upleft = matrix[i][j] + ((j > 0) ? prev[j - 1] : 1e9);
16                int upright = matrix[i][j] + ((j < m - 1) ? prev[j + 1] : 1e9);
17               temp[j] = min(up, min(upleft, upright));
18            }
19            prev=temp;
20        }
21
22        for (int i = 0; i < m; i++) {
23            ans = min(ans, prev[i]);
24        }
25
26        return ans;
27    }
28};