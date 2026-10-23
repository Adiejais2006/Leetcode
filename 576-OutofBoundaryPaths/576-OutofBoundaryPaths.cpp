// Last updated: 10/23/2026, 11:43:26 PM
1
2class Solution {
3
4public:
5    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
6        int MOD = 1e9 + 7;
7        vector<int> dx = {-1, 0, 0, 1};
8        vector<int> dy = {0, -1, 1, 0};
9        vector<vector<vector<long long>>> dp(
10            m + 1, vector<vector<long long>>(
11                       n + 1, vector<long long>(maxMove + 1, 0)));
12        for (int k = 1; k <= maxMove; k++) {
13            for (int i = 0; i < m; i++) {
14                for (int j = 0; j < n; j++) {
15
16                    int ans = 0;
17                    for (int l = 0; l < 4; l++) {
18                        int ni = i + dx[l];
19                        int nj = j + dy[l];
20                        if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
21                            ans = (ans+  1)%MOD;
22                        } else {
23                            ans = (ans + dp[ni][nj][k - 1]) % MOD;
24                        }
25                    }
26                    dp[i][j][k] = ans;
27                }
28            }
29        }
30        return dp[startRow][startColumn][maxMove];
31    }
32};
33