// Last updated: 10/19/2026, 11:25:38 AM
1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4
5        int n = matrix.size();
6        for (int i = 0; i < n; i++) {
7            for (int j = i; j < n; j++) {
8                if (i != j) {
9                    swap(matrix[i][j], matrix[j][i]);
10                }
11            }
12        }
13
14        for(int i = 0 ; i<n ; i++){
15            reverse(matrix[i].begin() , matrix[i].end());
16        }
17    }
18};