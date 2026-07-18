// Last updated: 7/18/2026, 2:03:16 PM
class DisjointSet {
   public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUpar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }
    bool find(int u, int v) {
        if (findUpar(u) == findUpar(v)) return true;
        return false;
    }
    void unionByRank(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;

        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;

        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);

        if (pu == pv) return;

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
            int n = grid.size();
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int dx[] = {-1, 0, 0, 1};
                int dy[] = {0, 1, -1, 0};
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if ((nx >= 0 && nx < n && ny >= 0 && ny < n) &&
                        grid[nx][ny] == 1) {
                        int nodeNo = i * n + j;
                        int adjNodeNo = nx * n + ny;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                set<int> st;
                if (grid[i][j] == 1) continue;
                int dx[] = {-1, 0, 0, 1};
                int dy[] = {0, 1, -1, 0};
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if ((nx >= 0 && nx < n && ny >= 0 && ny < n) &&
                        grid[nx][ny] == 1) {
                        int adjNodeNo = nx * n + ny;
                        st.insert(ds.findUpar(adjNodeNo));
                    }
                }
                int totalSize = 1;
                for (auto it : st) {
                    totalSize += ds.size[it];
                }
                ans = max(totalSize,ans);
            }
        }
        // jab saare h 1 1 ho
        for(int i = 0 ; i<n*n ;i++){
            ans = max(ans , ds.size[ds.findUpar(i)]);
        }
        return ans ;
    }
};