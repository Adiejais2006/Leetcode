// Last updated: 11/18/2026, 2:54:53 PM
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
4                          int k) {
5        vector<pair<int, int>> adj[n];
6        vector<int> dist(n, 1e9);
7        dist[src] = 0;
8        for (auto it : flights) {
9            int u = it[0];
10            int v = it[1];
11            int wt = it[2];
12            adj[u].push_back({v, wt});
13        }
14        queue<pair<int, pair<int, int>>> pq; // steps , node and wt
15        pq.push({0, {src, 0}});
16        while (!pq.empty()) {
17            auto [steps, nodeAndWt] = pq.front();
18            pq.pop();
19            auto [node, currwt] = nodeAndWt;
20            for (auto it : adj[node]) {
21                int adjNode = it.first;
22                int adjwt = it.second;
23                int totalwt = currwt + adjwt;
24                if (dist[adjNode] > totalwt && steps <= k) {
25                    dist[adjNode] = totalwt;
26                    pq.push({steps + 1, {adjNode, totalwt}});
27                }
28            }
29        }
30        if (dist[dst] == 1e9)
31            return -1;
32        else
33            return dist[dst];
34    }
35};