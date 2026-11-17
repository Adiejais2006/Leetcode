// Last updated: 11/17/2026, 1:13:36 PM
1class Solution {
2public:
3    int minimumChanges(string s, int k) {
4        int n = s.size();
5        const int INF = 1e9;
6        vector<vector<int>> cost(n, vector<int>(n, INF));
7        for (int i = 0; i < n; ++i) {
8            for (int j = i + 1; j < n; ++j) {
9                int L = j - i + 1;
10                int best = INF;
11                for (int d = 1; d < L; ++d) {
12                    if (L % d != 0) continue;
13                    int cur = 0;
14                    int m = L / d;
15                    for (int r = 0; r < d; ++r) {
16                        for (int t = 0; t < m / 2; ++t) {
17                            if (s[i + r + t * d] != s[i + r + (m - 1 - t) * d])
18                                ++cur;
19                        }
20                    }
21                    best = min(best, cur);
22                }
23                cost[i][j] = best;
24            }
25        }
26        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
27        dp[0][0] = 0;
28        for (int i = 1; i <= n; ++i) {
29            for (int p = 1; p <= k; ++p) {
30                for (int prev = 0; prev <= i - 2; ++prev) {
31                    if (dp[prev][p - 1] != INF && cost[prev][i - 1] != INF)
32                        dp[i][p] = min(dp[i][p], dp[prev][p - 1] + cost[prev][i - 1]);
33                }
34            }
35        }
36        return dp[n][k];
37    }
38};