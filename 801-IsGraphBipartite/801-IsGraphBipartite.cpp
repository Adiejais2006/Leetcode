// Last updated: 7/18/2026, 2:03:23 PM
class Solution { bool bfs(int start, vector<int> adj[], vector<int> &colour) {
        queue<pair<int, int>> q;
        // colour and node 
        colour[start] = 0;
        q.push({0, start});
        // initial color is 0
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int colr = it.first;
            int node = it.second;
            int newcolor = !colr;
            for (auto it : adj[node]) {
                if (colour[it] == -1) {
                    q.push({newcolor, it});
                    colour[it] = newcolor;
                } else {
                    if (colr == colour[it]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
         vector<int> adj[V];
        for (int i = 0 ; i<V ;i++) {
            for(int j = 0 ; j<graph[i].size() ;j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> colour(V, -1);
       

        for (int i = 0; i < V; i++) {
            if (colour[i] == -1) {
                if (!bfs(i, adj, colour)) return false;
            }
        }

        return true;
    }
};