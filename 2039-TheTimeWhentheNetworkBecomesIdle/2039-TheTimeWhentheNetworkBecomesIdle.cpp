// Last updated: 9/22/2026, 12:40:17 AM
1class Solution {
2public:
3    int networkBecomesIdle(vector<vector<int>>& edges,
4                           vector<int>& patience) {
5
6        int n = patience.size();
7        vector<int> adj[n];
8        for (auto &e : edges) {
9            int u = e[0];
10            int v = e[1];
11            adj[u].push_back(v);
12            adj[v].push_back(u);
13        }
14        vector<int> dist(n, -1);
15        queue<int> q;
16        q.push(0);
17        dist[0] = 0;
18        while (!q.empty()) {
19            int u = q.front();
20            q.pop();
21            for (int v : adj[u]) {
22                if (dist[v] == -1) {
23                    dist[v] = dist[u] + 1;
24                    q.push(v);
25                }
26            }
27        }
28        int ans = 0;
29        for (int i = 1; i < n; i++) {
30            int roundTrip = 2 * dist[i];
31            int lastSend =
32                ((roundTrip - 1) / patience[i]) * patience[i];
33            int idleTime = lastSend + roundTrip + 1;
34            ans = max(ans, idleTime);
35        }
36
37        return ans;
38    }
39};