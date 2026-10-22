// Last updated: 10/22/2026, 4:07:14 PM
1class Solution {
2
3public:
4    int maximalSquare(vector<vector<char>>& matrix) {
5        int n = matrix.size();
6        int m = matrix[0].size();
7        vector<int> prev(m + 1, 0);
8        vector<int> curr(m + 1, 0);
9        int ans = 0;
10        for (int i = 1; i <= n; i++) {
11            for (int j = 1; j <= m; j++) {
12                if (matrix[i - 1][j - 1] == '1') {
13                    int top = prev[j];
14                    int left = curr[j - 1];
15                    int diagonal = prev[j - 1];
16                    curr[j] = 1 + min(top, min(left, diagonal));
17                    ans = max(ans, curr[j]);
18                } else {
19                    curr[j] = 0;
20                }
21            }
22            prev = curr;
23        }
24        return ans * ans;
25    }
26};