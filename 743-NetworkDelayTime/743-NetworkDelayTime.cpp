// Last updated: 9/15/2026, 3:54:14 PM
1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        // making adjacency list
5        vector<pair<int, int>> adj[n + 1];
6        for (auto it : times) {
7            int u = it[0];
8            int v = it[1];
9            int wt = it[2];
10            adj[u].push_back({v, wt});
11        }
12        vector<int> dist(n + 1, 1e9);
13        priority_queue<pair<int, int>, vector<pair<int, int>>,
14                       greater<pair<int, int>>>
15            q;
16        q.push({0, k});
17        dist[k] = 0;
18        int ans = 0;
19        while (!q.empty()) {
20            auto [distance, node] = q.top();
21            q.pop();
22            for (auto it : adj[node]) {
23                int adjNode = it.first;
24                int adjDist = it.second;
25                int newDist = distance + adjDist;
26                if (dist[adjNode] > newDist) {
27                    dist[adjNode] = newDist;
28                    q.push({newDist, adjNode});
29                }
30            }
31        }
32        for (int i = 1; i <= n; i++) {
33            if (dist[i] == 1e9)
34                return -1;
35            ans = max(ans, dist[i]);
36        }
37        return ans;
38    }
39};