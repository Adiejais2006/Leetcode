// Last updated: 10/19/2026, 2:30:52 PM
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
17        vector<vector<int>> prev(m + 1, vector<int>(n + 1, 0));
18        vector<vector<int>> curr(m + 1, vector<int>(n + 1, 0));
19        for (int M = 0; M <= m; M++) {
20            for (int N = 0; N <= n; N++) {
21                if (ans[0].first <= M && ans[0].second <= N)
22                    prev[M][N] = 1;
23                else
24                    prev[M][N] = 0;
25            }
26        }
27        for (int i = 1; i < s; i++) {
28            for (int M = 0; M <= m; M++) {
29                for (int N = 0; N <= n; N++) {
30                    int nottake = prev[M][N];
31                    int take = 0;
32                    if (ans[i].first <= M && ans[i].second <= N) {
33                        take = 1 + prev[M - ans[i].first][N - ans[i].second];
34                    }
35                    curr[M][N] = max(take, nottake);
36                }
37            }
38            prev = curr;
39        }
40        return prev[m][n];
41    }
42};