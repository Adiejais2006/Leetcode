// Last updated: 10/19/2026, 11:30:47 AM
1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6        vector<int> row(m);
7        vector<int> col(n);
8        for (int i = 0; i < m; i++) {
9            for (int j = 0; j < n; j++) {
10                if (matrix[i][j] == 0) {
11                    row[i] = 1;
12                    col[j] = 1;
13                }
14            }
15        }
16        for (int i = 0; i < m; i++) {
17            for (int j = 0; j < n; j++) {
18                if (row[i] == 1 || col[j] == 1) {
19                    matrix[i][j] = 0;
20                }
21            }
22        }
23    }
24};