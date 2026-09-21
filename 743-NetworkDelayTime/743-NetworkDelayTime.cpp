// Last updated: 9/21/2026, 7:02:34 PM
1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        vector<pair<int, int>> adj[n + 1];
5        for (auto it : times) {
6            int u = it[0];
7            int v = it[1];
8            int wt = it[2];
9            adj[u].push_back({v, wt});
10        }
11        vector<int> dist(n + 1, 1e9);
12        dist[k] = 0;
13        priority_queue<pair<int, int>, vector<pair<int, int>>,
14                       greater<pair<int, int>>>
15            pq;
16        pq.push({0, k});
17        while (!pq.empty()) {
18            auto [currDist, node] = pq.top();
19            pq.pop();
20            for (auto it : adj[node]) {
21                int adjNode = it.first;
22                int adjWt = it.second;
23                int totalDist = currDist + adjWt;
24                if (totalDist < dist[adjNode]) {
25                    dist[adjNode] = totalDist;
26                    pq.push({totalDist, adjNode});
27                }
28            }
29        }
30        int ans = -1;
31        for (int i = 1; i <= n; i++) {
32            if (dist[i] == 1e9)
33                return -1;
34            ans = max(ans, dist[i]);
35        }
36        return ans;
37    }
38};