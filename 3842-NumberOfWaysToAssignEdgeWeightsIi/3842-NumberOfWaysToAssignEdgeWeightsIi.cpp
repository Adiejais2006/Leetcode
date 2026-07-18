// Last updated: 7/18/2026, 1:59:28 PM
class Solution {
public:
    static constexpr int MOD = 1'000'000'007;
    static constexpr int LOG = 17 + 1; // enough for n <= 1e5

    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;
    vector<vector<int>> g;

    void dfs(int u, int p) {
        up[0][u] = p;

        for (int k = 1; k < LOG; ++k) {
            if (up[k - 1][u] == -1)
                up[k][u] = -1;
            else
                up[k][u] = up[k - 1][up[k - 1][u]];
        }

        for (int v : g[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; ++k) {
            if (diff & (1 << k))
                a = up[k][a];
        }

        if (a == b) return a;

        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }

        return up[0][a];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        g.assign(n + 1, {});
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        up.assign(LOG, vector<int>(n + 1, -1));
        depth.assign(n + 1, 0);

        dfs(1, -1);

        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0], v = q[1];

            int w = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[w];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back((int)pow2[dist - 1]);
        }

        return ans;
    }
};