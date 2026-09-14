// Last updated: 9/14/2026, 1:19:53 PM
1class Solution {
2private:
3    int max_depth = 0;
4
5    void dfs(int node, int parent, int depth, const vector<vector<int>>& adj) {
6        if (depth > max_depth) {
7            max_depth = depth;
8        }
9        for (int neighbor : adj[node]) {
10            if (neighbor != parent) {
11                dfs(neighbor, node, depth + 1, adj);
12            }
13        }
14    }
15
16public:
17    int assignEdgeWeights(vector<vector<int>>& edges) {
18        int n = edges.size() + 1;
19        vector<vector<int>> adj(n + 1);
20        for (const auto& edge : edges) {
21            adj[edge[0]].push_back(edge[1]);
22            adj[edge[1]].push_back(edge[0]);
23        }
24
25        max_depth = 0;
26        dfs(1, 0, 0, adj);
27
28        if (max_depth == 0) {
29            return 0;
30        }
31
32        long long ans = 1;
33        long long base = 2;
34        int exp = max_depth - 1;
35        long long mod = 1e9 + 7;
36
37        while (exp > 0) {
38            if (exp % 2 == 1) {
39                ans = (ans * base) % mod;
40            }
41            base = (base * base) % mod;
42            exp /= 2;
43        }
44
45        return ans;
46    }
47};