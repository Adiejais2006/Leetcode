// Last updated: 9/21/2026, 11:47:53 PM
1class Solution {
2public:
3    int countPaths(int n, vector<vector<int>>& roads) {
4
5        const int MOD = 1e9 + 7;
6
7        vector<pair<int, int>> adj[n];
8
9        for (auto it : roads) {
10            int u = it[0];
11            int v = it[1];
12            int wt = it[2];
13
14            adj[u].push_back({v, wt});
15            adj[v].push_back({u, wt});
16        }
17
18        vector<int> ways(n, 0);
19        vector<long long> dist(n, 1e18);
20
21        dist[0] = 0;
22        ways[0] = 1;
23
24        priority_queue<
25            pair<long long, int>,
26            vector<pair<long long, int>>,
27            greater<pair<long long, int>>
28        > pq;
29
30        pq.push({0, 0});
31
32        while (!pq.empty()) {
33
34            auto [currdist, node] = pq.top();
35            pq.pop();
36
37            for (auto it : adj[node]) {
38
39                int adjNode = it.first;
40                int adjDist = it.second;
41
42                long long totalDist = currdist + adjDist;
43
44                if (totalDist < dist[adjNode]) {
45
46                    dist[adjNode] = totalDist;
47                    ways[adjNode] = ways[node];
48
49                    pq.push({totalDist, adjNode});
50                }
51                else if (totalDist == dist[adjNode]) {
52
53                    ways[adjNode] =
54                        (ways[adjNode] + ways[node]) % MOD;
55                }
56            }
57        }
58
59        return ways[n - 1];
60    }
61};