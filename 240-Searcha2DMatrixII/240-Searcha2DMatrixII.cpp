// Last updated: 7/21/2026, 11:45:47 PM
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4        int n = matrix.size();
5        int m = matrix[0].size();
6        int i = 0;
7        int j = m - 1;
8        while (i < n && j >= 0) {
9            if (matrix[i][j] == target)
10                return true;
11            else if (matrix[i][j] < target)
12                i++;
13            else
14                j--;
15        }return false;
16    }
17};