// Last updated: 11/9/2026, 3:37:07 PM
1class Solution {
2    class dsu {
3    private:
4        vector<int> size;
5        vector<int> parent;
6
7    public:
8        dsu(int n) {
9            size.resize(n + 1, 1);
10            parent.resize(n + 1);
11            for (int i = 0; i <= n; i++) {
12                parent[i] = i;
13            }
14        }
15
16        int upar(int i) {
17            if (i == parent[i])
18                return i;
19            return parent[i] = upar(parent[i]);
20        }
21        void unionsize(int a, int b) {
22            int ua = upar(a);
23            int ub = upar(b);
24            if (ua != ub) {
25                if (size[ua] > size[ub]) {
26                    size[ua] += size[ub];
27                    parent[ub] = ua;
28                } else {
29                    size[ub] += size[ua];
30                    parent[ua] = ub;
31                }
32            }
33        }
34    };
35
36public:
37    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
38        int n = edges.size();
39        dsu ds(n);
40        for(auto it: edges){
41            int a=it[0];
42            int b=it[1];
43            int ua = ds.upar(a);
44            int ub = ds.upar(b);
45
46            if(ua!=ub){
47                ds.unionsize(a,b);
48            }
49            else {
50                return {a,b};
51            }
52        }
53        return {};
54    }
55};