// Last updated: 9/16/2026, 2:32:16 PM
1class Solution {
2    int find(int i, vector<int> &parent) {
3        if (i == parent[i])
4            return i;
5        return parent[i] = find(parent[i],parent);
6    }
7
8public:
9    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
10        int n = edges.size();
11        vector<int> parent(n+1);
12        vector<int> size(n+1, 1);
13        for (int i = 0; i < n; i++)
14            parent[i] = i;
15        for (int i = 0; i < n; i++) {
16            int a = edges[i][0];
17            int b = edges[i][1];
18            int roota = find(a,parent);
19            int rootb = find(b,parent);
20            if (roota == rootb)
21                return {a, b};
22            if (roota != rootb) {
23                if (size[roota] > size[rootb]) {
24                    parent[rootb] = roota;
25                    size[roota] += size[rootb];
26                } else {
27                    parent[roota] = rootb;
28                    size[rootb] += size[roota];
29                }
30            }
31        }
32        return {};
33    }
34};