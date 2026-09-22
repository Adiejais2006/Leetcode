// Last updated: 9/22/2026, 9:32:41 PM
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
4                          int k) {
5        vector<int> dist(n, 1e9);
6        dist[src] = 0;
7        for (int i = 0; i < k + 1; i++) {
8            vector<int> temp = dist;
9            for (auto it : flights) {
10                int u = it[0];
11                int v = it[1];
12                int wt = it[2];
13                if (temp[u] != 1e9 && dist[u] + wt < temp[v]) {
14                    temp[v] = dist[u] + wt;
15                }
16            }   
17            dist = temp;
18        }
19        return dist[dst] == 1e9 ? -1 : dist[dst];
20    }
21};