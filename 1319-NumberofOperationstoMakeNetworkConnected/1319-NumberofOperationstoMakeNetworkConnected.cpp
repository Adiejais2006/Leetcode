// Last updated: 9/16/2026, 2:44:12 PM
1class DisjointSet {
2public:
3    vector<int> size;
4    vector<int> parent;
5
6    DisjointSet(int n) {
7        size.resize(n + 1, 1);
8        parent.resize(n + 1);
9
10        for(int i = 0; i <= n; i++) {
11            parent[i] = i;
12        }
13    }
14
15    int findUpar(int node) {
16        if(node == parent[node])
17            return node;
18
19        return parent[node] = findUpar(parent[node]);
20    }
21
22    void findUnionBysize(int u, int v) {
23        int pu = findUpar(u);
24        int pv = findUpar(v);
25
26        if(pu == pv)
27            return;
28
29        if(size[pu] > size[pv]) {
30            parent[pv] = pu;
31            size[pu] += size[pv];
32        }
33        else {
34            parent[pu] = pv;
35            size[pv] += size[pu];
36        }
37    }
38};
39
40class Solution {
41public:
42    int makeConnected(int n, vector<vector<int>>& Edge) {
43
44        DisjointSet ds(n);
45
46        int extra = 0;
47
48        for(auto it : Edge) {
49
50            int a = it[0];
51            int b = it[1];   // FIX
52
53            if(ds.findUpar(a) == ds.findUpar(b)) {
54                extra++;
55            }
56            else {
57                ds.findUnionBysize(a, b);
58            }
59        }
60
61        int cnt = 0;
62
63        for(int i = 0; i < n; i++) {
64            if(ds.parent[i] == i)
65                cnt++;
66        }
67
68        int required = cnt - 1;
69
70        if(required <= extra)
71            return required;
72
73        return -1;
74    }
75};