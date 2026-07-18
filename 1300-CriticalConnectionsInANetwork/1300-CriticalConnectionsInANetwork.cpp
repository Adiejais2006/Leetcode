// Last updated: 7/18/2026, 2:02:18 PM
class Solution { int timer = 1;

   private:
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[],
             vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                if (tin[node] < low[it]) {
                    bridges.push_back({it, node});
                }
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& E) {
         vector<int> adj[V];
        for (auto it : E) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V, 0);
        vector<int> tin(V, 0);
        vector<int> low(V, 0);
        vector<vector<int>> bridges;
        
            dfs(0, -1, vis, adj , tin, low, bridges);
       

        return bridges;
    }
};