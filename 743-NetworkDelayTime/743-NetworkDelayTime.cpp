// Last updated: 10/31/2026, 3:27:44 PM
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
11        queue<pair<int, int>> q;
12        q.push({0, k});
13        vector<int> dist(n + 1, 1e9);
14        dist[k] = 0;
15        while (!q.empty()) {
16            auto [time, node] = q.front();
17            q.pop();
18
19            for (auto it : adj[node]) {
20                int adjNode = it.first;
21                int adjTime = it.second;
22                int newTime = time + adjTime;
23                if (newTime < dist[adjNode]) {
24                    dist[adjNode] = newTime;
25                    q.push({newTime, adjNode});
26                }
27            }
28        }
29        int ans = 0;
30        for (int i = 1; i <= n; i++) {
31            if (dist[i] == 1e9)
32                return -1;
33            ans = max(ans, dist[i]);
34        }
35        return ans;
36    }
37};