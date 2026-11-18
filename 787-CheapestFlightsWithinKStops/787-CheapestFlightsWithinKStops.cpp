// Last updated: 11/18/2026, 2:52:47 PM
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
14        priority_queue<pair<int, pair<int, int>>,
15                       vector<pair<int, pair<int, int>>>,
16                       greater<pair<int, pair<int, int>>>>
17            pq; // steps , node and wt
18        pq.push({0, {src, 0}});
19        while (!pq.empty()) {
20            auto [steps, nodeAndWt] = pq.top();
21            pq.pop();
22            auto [node, currwt] = nodeAndWt;
23            for (auto it : adj[node]) {
24                int adjNode = it.first;
25                int adjwt = it.second;
26                int totalwt = currwt + adjwt;
27                if (dist[adjNode] > totalwt && steps <= k) {
28                    dist[adjNode] = totalwt;
29                    pq.push({steps + 1, {adjNode, totalwt}});
30                }
31            }
32        }
33        if (dist[dst] == 1e9)
34            return -1;
35        else
36            return dist[dst];
37    }
38};