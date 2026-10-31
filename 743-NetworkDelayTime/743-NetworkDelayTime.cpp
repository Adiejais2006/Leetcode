// Last updated: 10/31/2026, 3:35:33 PM
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
11        priority_queue<pair<int, int>, vector<pair<int, int>>,
12                       greater<pair<int, int>>>
13            q;
14        q.push({0, k});
15        vector<int> dist(n + 1, 1e9);
16        dist[k] = 0;
17        while (!q.empty()) {
18            auto [time, node] = q.top();
19            q.pop();
20            if (time > dist[node])
21                continue;
22            for (auto it : adj[node]) {
23                int adjNode = it.first;
24                int adjTime = it.second;
25                int newTime = time + adjTime;
26                if (newTime < dist[adjNode]) {
27                    dist[adjNode] = newTime;
28                    q.push({newTime, adjNode});
29                }
30            }
31        }
32        int ans = 0;
33        for (int i = 1; i <= n; i++) {
34            if (dist[i] == 1e9)
35                return -1;
36            ans = max(ans, dist[i]);
37        }
38        return ans;
39    }
40};