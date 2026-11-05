// Last updated: 11/5/2026, 3:59:37 PM
1class Solution {
2    void dfs(int node, int parent,
3             vector<pair<int, int>> adj[], int &ans) {
4        for (auto [it, cost] : adj[node]) {
5            if (it == parent)
6                continue;
7
8            ans += cost;
9            dfs(it, node, adj, ans);
10        }
11    }
12
13public:
14    int minReorder(int n, vector<vector<int>>& connections) {
15        vector<pair<int, int>> adj[n];
16        for (auto it : connections) {
17            int u = it[0];
18            int v = it[1];
19            adj[u].push_back({v, 1});
20            adj[v].push_back({u, 0});
21        }
22        int ans = 0;
23        dfs(0, -1, adj, ans);
24        return ans;
25    }
26};