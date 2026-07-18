// Last updated: 7/18/2026, 2:02:04 PM
class DisjointSet {
public:
    vector<int> rank;
    vector<int> parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    bool find(int u, int v) {
        if (findUpar(u) == findUpar(v))
            return true;
        return false;
    }

    void findUnionByRank(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);
        if (pu == pv)
            return;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pv] > rank[pu]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& Edge) {
        DisjointSet ds(n);
        int extra = 0;
        for (auto it : Edge) {
            int u = it[0];
            int v = it[1];
            if (ds.findUpar(u) == ds.findUpar(v))
                extra++;
            else
                ds.findUnionByRank(u, v);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                cnt++;
            }
        }
        int ans = cnt - 1;
        if (ans <= extra)
            return ans;
        return -1;
    }
};