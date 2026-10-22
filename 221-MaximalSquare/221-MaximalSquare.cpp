// Last updated: 10/22/2026, 4:04:52 PM
1class Solution {
2public:
3    int maximalSquare(vector<vector<char>>& matrix) {
4        int n = matrix.size();
5        int m = matrix[0].size();
6        vector<int> prev(m + 1, 0);
7        vector<int> curr(m + 1, 0);
8        int maxSide = 0;
9        for (int i = 1; i <= n; i++) {
10            for (int j = 1; j <= m; j++) {
11                if (matrix[i - 1][j - 1] == '1') {
12                    curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
13                    maxSide = max(maxSide, curr[j]);
14                } else {
15                    curr[j] = 0;
16                }
17            }
18            prev = curr;
19        }
20
21        return maxSide * maxSide;
22    }
23};
24