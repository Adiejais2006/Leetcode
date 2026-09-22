// Last updated: 9/22/2026, 10:41:00 PM
1class Solution {
2public:
3    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
4                                         vector<vector<int>>& blueEdges) {
5        vector<vector<int>> dist(n, vector<int>(2, 1e9));
6        dist[0][0]= 0 ;
7        dist[0][1] = 0 ;
8        vector<pair<int, int>> adj[n]; // color and v
9        for (auto it : redEdges) {
10            int u = it[0];
11            int v = it[1];
12            adj[u].push_back({1, v});
13        }
14        for (auto it : blueEdges) {
15            int u = it[0];
16            int v = it[1];
17            adj[u].push_back({0, v});
18        }
19        priority_queue<pair<int, pair<int, int>>,
20                       vector<pair<int, pair<int, int>>>,
21                       greater<pair<int, pair<int, int>>>>
22            pq; // dist node and color
23        pq.push({0, {0, -1}});
24        while (!pq.empty()) {
25            auto [currDist, nodeColor] = pq.top();
26            pq.pop();
27            int node = nodeColor.first;
28            int currColor = nodeColor.second;
29
30            for (auto it : adj[node]) {
31                int adjColor = it.first;
32                int adjNode = it.second;
33                if (currColor == adjColor)
34                    continue;
35                int totalDist = currDist + 1;
36
37                if (totalDist < dist[adjNode][adjColor]) {
38                    dist[adjNode][adjColor] = totalDist;
39                    pq.push({totalDist, {adjNode, adjColor}});
40                }
41            }
42        }
43        vector<int> ans(n);
44        for (int i = 0; i < n; i++) {
45            ans[i] = min(dist[i][0], dist[i][1]);
46            if (ans[i] == 1e9)
47                ans[i] = -1;
48        }
49        return ans;
50    }
51};