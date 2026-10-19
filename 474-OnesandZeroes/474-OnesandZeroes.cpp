// Last updated: 10/19/2026, 2:26:54 PM
1class Solution {
2public:
3    int findMaxForm(vector<string>& strs, int m, int n) {
4        int s = strs.size();
5        vector<pair<int, int>> ans; // index pr store krega 0 or 1
6        for (auto it : strs) {
7            int z = 0;
8            int o = 0;
9            for (auto a : it) {
10                if (a == '0')
11                    z++;
12                else
13                    o++;
14            }
15            ans.push_back({z, o});
16        }
17        vector<vector<vector<int>>> dp(
18            s, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
19        for (int M = 0; M <= m; M++) {
20            for (int N = 0; N <= n; N++) {
21                if (ans[0].first <= M && ans[0].second <= N)
22                    dp[0][M][N] = 1;
23                else
24                    dp[0][M][N] = 0;
25            }
26        }
27        for (int i = 1; i < s; i++) {
28            for (int M = 0; M <= m; M++) {
29                for (int N = 0; N <= n; N++) {
30                    int nottake = dp[i - 1][M][N];
31                    int take = 0;
32                    if (ans[i].first <= M && ans[i].second <= N) {
33                        take =
34                            1 + dp[i - 1][M - ans[i].first][N - ans[i].second];
35                    }
36                    dp[i][M][N] = max(take, nottake);
37                }
38            }
39        }
40        return dp[s - 1][m][n];
41    }
42};