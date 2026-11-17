// Last updated: 11/17/2026, 4:36:44 PM
1class Solution {
2public:
3    double maxProbability(int n, vector<vector<int>>& edges,
4                          vector<double>& succProb, int start_node,
5                          int end_node) {
6        vector<pair<int, double>> adj[n];
7        int i = 0;
8        for (auto it : edges) {
9            int u = it[0];
10            int v = it[1];
11            double wt = succProb[i++];
12            adj[u].push_back({v, wt});
13            adj[v].push_back({u, wt});
14        }
15        vector<double> dist(n, 0);
16        priority_queue<pair<double, int>> pq;
17        dist[start_node] = 1;
18        pq.push({1.00, start_node});
19        while (!pq.empty()) {
20            auto [currprobab, node] = pq.top();
21            pq.pop();
22            for (auto it : adj[node]) {
23                double adjprobab = it.second;
24                int adjNode = it.first;
25                double totalprobab = currprobab * adjprobab;
26                if (dist[adjNode] < totalprobab) {
27                    dist[adjNode] = totalprobab;
28                    pq.push({totalprobab, adjNode});
29                }
30            }
31        }
32        return dist[end_node];
33    }
34};