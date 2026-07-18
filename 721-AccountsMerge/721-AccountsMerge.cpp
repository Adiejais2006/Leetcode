// Last updated: 7/18/2026, 2:03:37 PM
class DisjointSet {
   private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

   public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findUPar(parent[u]);
    }

    bool find(int u, int v) { return (findUPar(u) == findUPar(v)); }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;  // attach smaller rank under larger
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
         int n = accounts.size();
        DisjointSet ds(accounts.size());
        map<string, int> mpp;
        // isse hamara inital graph ban jayega ki kon kisme hai
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
            string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end()) {
                    mpp[mail] = i;
                } else {
                    ds.unionByRank(mpp[mail], i);
                }
            }
        }

        // ab map se utha kr ek llist bana rhe hai ki kon kime h

        vector<string>
            mergedmail[n];  // adjancy list type hai ye dont congfguse

        for (auto it : mpp) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedmail[node].push_back(mail);
        }


        // isme rearrange kr rhe hai sort kr rhe hai acciording to questiokn
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedmail[i].size() == 0) continue;

            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedmail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }


        return ans ;
    }
};