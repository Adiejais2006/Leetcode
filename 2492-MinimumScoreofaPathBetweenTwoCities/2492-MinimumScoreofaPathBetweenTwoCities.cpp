// Last updated: 9/20/2026, 2:41:19 PM
1class Solution {
2    void dfs(int node, vector<int>& vis,
3             vector<pair<int,int>> adj[], int& ans) {
4        vis[node] = 1;
5        for (auto it : adj[node]) {
6            int next = it.first;
7            int wt = it.second;
8            ans = min(ans, wt);
9            if (!vis[next]) {
10                dfs(next, vis, adj, ans);
11            }
12        }
13    }
14public:
15    int minScore(int n, vector<vector<int>>& roads) {
16        vector<pair<int,int>> adj[n + 1];
17        for (auto it : roads) {
18            int u = it[0];
19            int v = it[1];
20            int wt = it[2];
21            adj[u].push_back({v, wt});
22            adj[v].push_back({u, wt});
23        }
24        vector<int> vis(n + 1, 0);
25        int ans = INT_MAX;
26        dfs(1, vis, adj, ans);
27        return ans;
28    }
29};