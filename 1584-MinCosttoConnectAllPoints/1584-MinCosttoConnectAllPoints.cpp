// Last updated: 11/17/2026, 4:00:57 PM
1class Solution {
2    class DSU {
3        vector<int> parent, size;
4
5    public:
6        DSU(int n) {
7            parent.resize(n);
8            size.assign(n, 1);
9            iota(parent.begin(), parent.end(), 0);
10        }
11
12        int find(int x) {
13            if (parent[x] == x)
14                return x;
15
16            return parent[x] = find(parent[x]);
17        }
18
19        void unionBySize(int u, int v) {
20            u = find(u);
21            v = find(v);
22
23            if (u == v)
24                return;
25
26            if (size[u] < size[v])
27                swap(u, v);
28
29            parent[v] = u;
30            size[u] += size[v];
31        }
32    };
33
34public:
35    int minCostConnectPoints(vector<vector<int>>& points) {
36        int n = points.size();
37        vector<vector<int>> weights;
38        for (int i = 0; i < n; i++) {
39            for (int j = i + 1; j < n; j++) {
40                int wt = abs(points[i][0] - points[j][0]) +
41                         abs(points[i][1] - points[j][1]);
42                int u = i;
43                int v = j;
44                weights.push_back({wt, u, v});
45            }
46        }
47        sort(weights.begin(), weights.end());
48        DSU ds(n);
49        int ans = 0;
50        for (auto it : weights) {
51            int wt = it[0];
52            int u = it[1];
53            int v = it[2];
54            if (ds.find(u) != ds.find(v)) {
55                ds.unionBySize(u, v);
56                ans += wt;
57            }
58        }
59        return ans;
60    }
61};