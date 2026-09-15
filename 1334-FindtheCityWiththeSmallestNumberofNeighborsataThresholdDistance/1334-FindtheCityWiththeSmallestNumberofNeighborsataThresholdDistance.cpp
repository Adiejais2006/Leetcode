// Last updated: 9/15/2026, 11:35:15 PM
1class Solution {
2public:
3    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
4        vector<vector<int>> dist(n, vector<int>(n, 1e9));
5        for (auto e : edges) {
6            int u = e[0];
7            int v = e[1];
8            int wt = e[2];
9            dist[u][v] = wt;
10            dist[v][u] = wt;
11        }
12        for(int i = 0 ; i<n ; i++) dist[i][i] = 0 ;
13        for (int k = 0; k < n; k++) {
14            for (int i = 0; i < n; i++) {
15                for (int j = 0; j < n; j++) {
16                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
17                }
18            }
19        }
20        int city = -1;
21        int ans = INT_MAX;
22        for (int i = 0; i < n; i++) {
23            int cnt = 0;
24            for (int j = 0; j < n; j++) {
25                if (dist[i][j] <= distanceThreshold) {
26                    cnt++;
27                }
28            }
29            if (ans >= cnt) {
30                ans = cnt;
31                city = i;
32            }
33        }
34        return city;
35    }
36};