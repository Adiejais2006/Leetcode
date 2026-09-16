// Last updated: 9/16/2026, 7:33:37 PM
1class DSU {
2private:
3    vector<int> size;
4    vector<int> parent;
5
6public:
7    DSU(int n) {
8        size.resize(n + 1, 1);
9        parent.resize(n + 1);
10        for (int i = 0; i <= n; i++)
11            parent[i] = i;
12    }
13
14    int find(int i) {
15        if (i == parent[i])
16            return i;
17        return parent[i] = find(parent[i]);
18    }
19
20    void unionsize(int a, int b) {
21        int upa = find(a);
22        int upb = find(b);
23        if (upa != upb) {
24            if (size[upa] > size[upb]) {
25                parent[upb] = upa;
26                size[upa] += size[upb];
27            } else {
28                parent[upa] = upb;
29                size[upb] += size[upa];
30            }
31        }
32    }
33};
34class Solution {
35public:
36    int removeStones(vector<vector<int>>& stones) {
37        int n = stones.size();
38        int maxRow=0;int maxCol = 0;
39        for (auto it : stones) {
40            maxRow = max(maxRow, it[0]);
41            maxCol = max(maxCol, it[1]);
42        }
43        DSU ds(maxRow + maxCol + 1);
44        unordered_map<int, int> stoneNodes;
45        for (int i = 0; i < n; i++) {
46            int row = stones[i][0];
47            int col = stones[i][1] + maxRow + 1;
48            ds.unionsize(row, col);
49            stoneNodes[row] = 1;
50            stoneNodes[col] = 1;
51        }
52        int k = 0;
53        for (auto it : stoneNodes) {
54            if (ds.find(it.first) == it.first) {
55                k++;
56            }
57        }
58        return n - k;
59    }
60};