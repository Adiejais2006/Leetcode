// Last updated: 11/12/2026, 6:38:28 PM
1class Solution {
2
3public:
4    int minFallingPathSum(vector<vector<int>>& matrix) {
5        int n = matrix.size();
6        vector<int> prev(n, 0);
7        vector<int> curr(n, 0);
8        for (int j = 0; j < n; j++) {
9            prev[j] = matrix[0][j];
10        }
11        for (int i = 1; i < n; i++) {
12            for (int j = 0; j < n; j++) {
13                int top = prev[j];
14                // if (j < 0 || j >= n)
15                //     return INT_MAX;
16                int topleft = j - 1 >= 0 ? prev[j - 1] : INT_MAX;
17                int topright = j + 1 < n ? prev[j + 1] : INT_MAX;
18               curr[j] = matrix[i][j] + min(top, min(topleft, topright));
19            }
20            prev=curr;
21        }
22        int ans = INT_MAX;
23        for (int i = 0; i < n; i++) {
24            ans = min(ans,prev[i]);
25        }
26        return ans;
27    }
28};