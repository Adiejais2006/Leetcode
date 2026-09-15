// Last updated: 9/15/2026, 6:36:06 PM
1class Solution {
2public:
3    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
4                          int k) {
5        vector<pair<int, int>> adj[n];
6        vector<int> dist(n, 1e9);
7        dist[src] = 0 ; 
8        for (auto it : flights) {
9            int u = it[0];
10            int v = it[1];
11            int wt = it[2];
12            adj[u].push_back({v, wt});
13        }
14        priority_queue<pair<int, pair<int, int>>,
15                       vector<pair<int, pair<int, int>>>,
16                       greater<pair<int, pair<int, int>>>>
17            q;
18        q.push({0, {0, src}}); // stops dist and nodes
19        while (!q.empty()) {
20            auto i = q.top();
21            q.pop();
22            int stops = i.first;
23            int d = i.second.first;
24            int node = i.second.second;
25            for (auto it : adj[node]) {
26                int adjNode = it.first;
27                int adjDist = it.second;
28                int newDist = d + adjDist;
29                if (stops > k)
30                    continue;
31                if (dist[adjNode] > newDist) {
32                    dist[adjNode] = newDist;
33                    q.push({stops+1, {newDist, adjNode}});
34                }
35            }
36        }
37        if (dist[dst] == 1e9)
38            return -1;
39        return dist[dst];
40    }
41};
42