// Last updated: 7/18/2026, 1:59:26 PM
class Solution {
private:
    int max_depth = 0;

    void dfs(int node, int parent, int depth, const vector<vector<int>>& adj) {
        if (depth > max_depth) {
            max_depth = depth;
        }
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, adj);
            }
        }
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        max_depth = 0;
        dfs(1, 0, 0, adj);

        if (max_depth == 0) {
            return 0;
        }

        long long ans = 1;
        long long base = 2;
        int exp = max_depth - 1;
        long long mod = 1e9 + 7;

        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }

        return ans;
    }
};