// Last updated: 9/11/2026, 2:13:58 AM
1class Solution {
2    vector<vector<int>> adj;
3    vector<int> subtreeSize;
4    vector<int> ans;
5    void dfs1(int node, int parent, int depth) {
6        subtreeSize[node] = 1;
7        ans[0] += depth;
8        for (int child : adj[node]) {
9            if (child == parent)
10                continue;
11            dfs1(child, node, depth + 1);
12            subtreeSize[node] += subtreeSize[child];
13        }
14    }
15    void dfs2(int node, int parent, int n) {
16        for (int child : adj[node]) {
17            if (child == parent)
18                continue;
19            ans[child] = ans[node]
20                       - subtreeSize[child]
21                       + (n - subtreeSize[child]);
22            dfs2(child, node, n);
23        }
24    }
25public:
26    vector<int> sumOfDistancesInTree(
27        int n,
28        vector<vector<int>>& edges
29    ) {
30        adj.resize(n);
31        subtreeSize.resize(n);
32        ans.resize(n);
33        for (auto& edge : edges) {
34            int u = edge[0];
35            int v = edge[1];
36            adj[u].push_back(v);
37            adj[v].push_back(u);
38        }
39        dfs1(0, -1, 0);
40        dfs2(0, -1, n);
41        return ans;
42    }
43};