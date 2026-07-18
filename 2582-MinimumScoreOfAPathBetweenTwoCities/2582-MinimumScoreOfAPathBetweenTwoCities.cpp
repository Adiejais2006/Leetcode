// Last updated: 7/18/2026, 2:00:32 PM
class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int, int>>>& adj,
             vector<bool>& vis) {
        vis[node] = true;

        for (auto &[nei, wt] : adj[node]) {
            ans = min(ans, wt);

            if (!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<bool> vis(n + 1, false);
        dfs(1, adj, vis);

        return ans;
    }
};