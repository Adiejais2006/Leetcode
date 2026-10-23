// Last updated: 10/23/2026, 11:47:06 PM
1
2class Solution {
3
4public:
5    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
6        int MOD = 1e9 + 7;
7        vector<int> dx = {-1, 0, 0, 1};
8        vector<int> dy = {0, -1, 1, 0};
9        vector<vector<int>> prev(m, vector<int>(n, 0));
10        vector<vector<int>> curr(m, vector<int>(n, 0));
11        for (int k = 1; k <= maxMove; k++) {
12            for (int i = 0; i < m; i++) {
13                for (int j = 0; j < n; j++) {
14                    int ans = 0;
15                    for (int l = 0; l < 4; l++) {
16                        int ni = i + dx[l];
17                        int nj = j + dy[l];
18                        if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
19                            ans = (ans + 1) % MOD;
20                        } else {
21                            ans = (ans + prev[ni][nj] ) % MOD;
22                        }
23                    }
24                    curr[i][j] = ans;
25                }
26            }
27            prev = curr;
28        }
29        return prev[startRow][startColumn];
30    }
31};
32