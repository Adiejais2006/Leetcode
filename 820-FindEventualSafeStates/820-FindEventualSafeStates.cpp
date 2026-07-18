// Last updated: 7/18/2026, 2:03:19 PM
class Solution {
    bool detect(int node, vector<int>& vis, vector<int>& path,
                vector<int> adj[], vector<int>& check) {
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (detect(it, vis, path, adj, check)) {
                    check[node] = 0;
                    return true;
                }
            } else if (path[it] == 1) {
                return true;
            }
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for(int i = 0 ; i<V; i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        vector<int> check(V, 0);
        vector<int> safenodes;
        for (int i = 0; i < V; i++) {
            detect(i, vis, path, adj, check);
        }
        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safenodes.push_back(i);
        }
        return safenodes;
    }
};