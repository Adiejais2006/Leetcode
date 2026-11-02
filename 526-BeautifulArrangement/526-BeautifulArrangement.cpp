// Last updated: 11/3/2026, 12:10:19 AM
1class Solution {
2public:
3    int ans = 0;
4
5    void solve(int idx, int n, vector<int>& vis) {
6
7        if (idx > n) {
8            ans++;
9            return;
10        }
11
12        for (int i = 1; i <= n; i++) {
13
14            if (vis[i]) continue;
15
16            if (i % idx == 0 || idx % i == 0) {
17
18                vis[i] = 1;
19
20                solve(idx + 1, n, vis);
21
22                vis[i] = 0;
23            }
24        }
25    }
26
27    int countArrangement(int n) {
28
29        vector<int> vis(n + 1, 0);
30
31        solve(1, n, vis);
32
33        return ans;
34    }
35};