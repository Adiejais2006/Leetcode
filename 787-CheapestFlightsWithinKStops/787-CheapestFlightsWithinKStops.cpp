// Last updated: 10/26/2026, 3:20:05 PM
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
4                          int k) {
5        vector<pair<int, int>> adj[n];
6        for (auto it : flights) {
7            int u = it[0];
8            int v = it[1];
9            int wt = it[2];
10            adj[u].push_back({v, wt});
11        }
12        queue<pair<int, pair<int, int>>> q; // k , node , distance
13        vector<int> dist(n, 1e9);
14        dist[src] = 0;
15        q.push({k, {src, 0}});
16        while (!q.empty()) {
17            auto [steps, details] = q.front();
18            auto node = details.first;
19            auto distance = details.second;
20            q.pop();
21            for (auto it : adj[node]) {
22                int adjNode = it.first;
23                int adjDist = it.second;
24                long long netDistance = distance + adjDist;
25                if (steps < 0)
26                    continue;
27                if (dist[adjNode] > netDistance) {
28                    dist[adjNode] = netDistance;
29                    q.push({steps - 1, {adjNode, netDistance}});
30                }
31            }
32        }
33        if (dist[dst] == 1e9)
34            return -1;
35        return dist[dst];
36    }
37};