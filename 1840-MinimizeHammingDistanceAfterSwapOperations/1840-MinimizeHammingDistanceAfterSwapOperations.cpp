// Last updated: 7/18/2026, 2:01:36 PM
class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {

        int n = source.size();

        DSU ds(n);

        for (auto& it : allowedSwaps) {
            ds.unionBySize(it[0], it[1]);
        }

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            int parent = ds.findPar(i);
            groups[parent].push_back(i);
        }

        int ans = 0;

        for (auto& group : groups) {

            unordered_map<int, int> freq;

            for (auto idx : group.second) {
                freq[source[idx]]++;
            }

            for (auto idx : group.second) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};