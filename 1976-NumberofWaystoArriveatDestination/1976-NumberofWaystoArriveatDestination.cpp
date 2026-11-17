// Last updated: 11/17/2026, 4:50:34 PM
1class Solution {
2public:
3    int countPaths(int n, vector<vector<int>>& roads) {
4        long long MOD = 1e9 + 7;
5        vector<pair<long long, long long>> adj[n];
6        for (auto it : roads) {
7            long long u = it[0];
8            long long v = it[1];
9            long long wt = it[2];
10            adj[u].push_back({v, wt});
11            adj[v].push_back({u, wt});
12        }
13        vector<long long> dist(n, LLONG_MAX);
14        vector<long long> ways(n, 0);
15        dist[0] = 0;
16        ways[0] = 1;
17        priority_queue<pair<long long, long long>,
18                       vector<pair<long long, long long>>,
19                       greater<pair<long long, long long>>>
20            pq;
21        pq.push({0, 0});
22        ways[0] = 1;
23        while (!pq.empty()) {
24            auto [currwt, node] = pq.top();
25            pq.pop();
26            for (auto it : adj[node]) {
27                long long adjNode = it.first;
28                long long adjwt = it.second;
29                long long totalwt = currwt + adjwt;
30                if (currwt > dist[node])
31                    continue;
32                if (dist[adjNode] > totalwt) {
33                    dist[adjNode] = totalwt;
34                    pq.push({totalwt, adjNode});
35                    ways[adjNode] = ways[node];
36                } else if (dist[adjNode] == totalwt) {
37                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
38                }
39            }
40        }
41        return ways[n - 1];
42    }
43};