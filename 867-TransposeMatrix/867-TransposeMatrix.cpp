// Last updated: 9/26/2026, 2:46:17 PM
1class Solution {
2public:
3    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
4
5        int m = matrix.size();
6        int n = matrix[0].size();
7
8        vector<vector<int>> result(n, vector<int>(m,0));
9
10        for(int i = 0; i < m; i++) {
11
12            for(int j = 0 ; j < n; j++) {
13
14                result[j][i]= matrix[i][j];
15            }
16        }
17        return result;        
18    }
19};