// Last updated: 9/20/2026, 3:33:16 PM
1class DisjointSet {
2public:
3    vector<int> size;
4    vector<int> parent;
5    vector<int> edgeCount;
6    DisjointSet(int n) {
7        size.resize(n + 1, 1);
8        parent.resize(n + 1);
9        edgeCount.resize(n + 1, 0);
10        for (int i = 0; i <= n; i++) {
11            parent[i] = i;
12        }
13    }
14    int find(int node) {
15        if (node == parent[node])
16            return node;
17
18        return parent[node] = find(parent[node]);
19    }
20    void unionsize(int u, int v) {
21        int pu = find(u);
22        int pv = find(v);
23
24        if (pu == pv) {
25            edgeCount[pu]++;
26            return;
27        }
28
29        if (size[pu] > size[pv]) {
30            parent[pv] = pu;
31            size[pu] += size[pv];
32            edgeCount[pu] += edgeCount[pv]+1;
33        } else {
34            parent[pu] = pv;
35            size[pv] += size[pu];
36            edgeCount[pv] += edgeCount[pu]+1;
37        }
38    }
39};
40class Solution {
41public:
42    int countCompleteComponents(int n, vector<vector<int>>& edges) {
43        DisjointSet ds(n);
44        for (auto it : edges) {
45
46            int u = it[0];
47            int v = it[1];
48
49            ds.unionsize(u, v);
50        }
51        int cnt = 0 ;
52        for(int i =0 ; i<n ; i++){
53            if(ds.parent[i]==i){
54            int size = ds.size[i];
55            int edge = ds.edgeCount[i];
56            if((size*(size-1)/2)==edge)cnt++;}
57        }
58        return cnt;
59    }
60};