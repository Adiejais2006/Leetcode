// Last updated: 9/20/2026, 2:41:15 PM
1class Solution {
2    void bfs(int src, vector<vector<int>>& adj, vector<int>& vis,
3             long long& nodes, long long& degreeSum) {
4
5        queue<int> q;
6        q.push(src);
7        vis[src] = 1;
8
9        while (!q.empty()) {
10            int node = q.front();
11            q.pop();
12            nodes++;
13            degreeSum += adj[node].size();
14            for (auto it : adj[node]) {
15                if (!vis[it]) {
16                    vis[it] = 1;
17                    q.push(it);
18                }
19            }
20        }
21    }
22
23public:
24    int countCompleteComponents(int n, vector<vector<int>>& edges) {
25
26        vector<vector<int>> adj(n);
27
28        for (auto& e : edges) {
29            int u = e[0];
30            int v = e[1];
31
32            adj[u].push_back(v);
33            adj[v].push_back(u);
34        }
35
36        vector<int> vis(n, 0);
37        int cnt = 0;
38
39        for (int i = 0; i < n; i++) {
40
41            if (!vis[i]) {
42
43                long long nodes = 0;
44                long long degreeSum = 0;
45
46                bfs(i, adj, vis, nodes, degreeSum);
47
48                long long edgeCount = degreeSum / 2;
49
50                if (edgeCount == nodes * (nodes - 1) / 2)
51                    cnt++;
52            }
53        }
54
55        return cnt;
56    }
57};