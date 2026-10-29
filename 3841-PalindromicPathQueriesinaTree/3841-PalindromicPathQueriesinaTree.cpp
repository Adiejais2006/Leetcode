// Last updated: 10/29/2026, 11:33:29 AM
1class Solution {
2private:
3    int n;
4    vector<vector<int>> adj;
5    vector<int> parent, depth, heavy, head, pos, val;
6    int curPos;
7
8    struct SegmentTree{
9        int size;
10        vector<int> tree;
11
12        SegmentTree(int n){
13            size = n;
14            tree.assign(4 * n, 0);
15        }
16
17        void update(int node, int start, int end, int idx, int val){
18            if(start == end){
19                tree[node] = val;
20                return;
21            }
22
23            int mid = start + (end - start) / 2;
24            if(idx <= mid){
25                update(2 * node, start, mid, idx, val);
26            }else{
27                update(2 * node + 1, mid + 1, end, idx, val);
28            }
29
30            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
31        }
32
33        int query(int node, int start, int end, int l, int r){
34            if(r < start || end < l){
35                return 0;
36            }
37            if(l <= start && end <= r){
38                return tree[node];
39            }
40
41            int mid = start + (end - start) / 2;
42            return query(2 * node, start, mid, l, r) ^ query(2 * node + 1, mid + 1, end, l, r);
43        }
44    };
45
46    int dfs(int u, int p, int d){
47        depth[u] = d;
48        parent[u] = p;
49
50        int size = 1;
51        int maxChildSize = 0;
52
53        for(int v : adj[u]){
54            if(v != p){
55                int childSize = dfs(v, u, d + 1);
56                size += childSize;
57
58                if(childSize > maxChildSize){
59                    maxChildSize = childSize;
60                    heavy[u] = v;
61                }
62            }
63        }
64
65        return size;
66    }
67
68    void decompose(int u, int h){
69        head[u] = h;
70        pos[u] = curPos++;
71
72        if(heavy[u] != -1){
73            decompose(heavy[u], h);
74        }
75
76        for(int v : adj[u]){
77            if(v != parent[u] && v != heavy[u]){
78                decompose(v, v);
79            }
80        }
81    }
82
83    int queryPath(int u, int v, SegmentTree& segTree){
84        int res = 0;
85
86        while(head[u] != head[v]){
87            if(depth[head[u]] > depth[head[v]]){
88                swap(u, v);
89            }
90
91            res ^= segTree.query(1, 0, n - 1, pos[head[v]], pos[v]);
92            v = parent[head[v]];
93        }
94
95        if(depth[u] > depth[v]){
96            swap(u, v);
97        }
98
99        res ^= segTree.query(1, 0, n - 1, pos[u], pos[v]);
100        return res;
101    }
102
103public:
104    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries){
105        this->n = n;
106        adj.assign(n, vector<int>());
107
108        for(const auto& e : edges){
109            adj[e[0]].push_back(e[1]);
110            adj[e[1]].push_back(e[0]);
111        }
112
113        parent.assign(n, 0);
114        depth.assign(n, 0);
115        heavy.assign(n, -1);
116        head.assign(n, 0);
117        pos.assign(n, 0);
118
119        dfs(0, -1, 0);
120
121        curPos = 0;
122        decompose(0, 0);
123
124        SegmentTree segTree(n);
125        val.resize(n);
126
127        for(int i = 0; i < n; i++){
128            val[i] = 1 << (s[i] - 'a');
129            segTree.update(1, 0, n - 1, pos[i], val[i]);
130        }
131
132        vector<bool> ans;
133
134        for(const string& q : queries){
135            stringstream ss(q);
136            string type;
137            ss >> type;
138            if(type == "update"){
139                int u;
140                char c;
141                ss >> u >> c;
142                val[u] = 1 << (c - 'a');
143                segTree.update(1, 0, n - 1, pos[u], val[u]);
144            }else{
145                int u, v;
146                ss >> u >> v;
147                int mask = queryPath(u, v, segTree);
148                ans.push_back((mask & (mask - 1)) == 0);
149            }
150        }
151        return ans;
152    }
153};