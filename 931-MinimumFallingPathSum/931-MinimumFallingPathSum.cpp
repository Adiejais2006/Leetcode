// Last updated: 10/18/2026, 2:26:19 PM
1class Solution {
2
3public:
4    int minFallingPathSum(vector<vector<int>>& matrix) {
5        int n = matrix.size();
6        int anss = INT_MAX;
7        vector<int> prev(n, 0);
8        vector<int> curr(n, 0);
9        for (int i = 0; i < n; i++) {
10            prev[i] = matrix[0][i];
11        }
12        for (int i = 1; i < n; i++) {
13            for (int j = 0; j < n; j++) {
14                int downleft = j > 0 ? prev[j - 1] : INT_MAX;
15                int downright = j < n - 1 ? prev[j + 1] : INT_MAX;
16                int down = prev[j];
17                int best = min(downleft, min(downright, down));
18                if (best == INT_MAX) {
19                    curr[j] = INT_MAX;
20                    continue;
21                }
22                curr[j] = matrix[i][j] + best;
23            }
24            prev = curr;
25        }
26        for (int i = 0; i < n; i++)
27            anss = min(anss, prev[i]);
28        return anss;
29    }
30};