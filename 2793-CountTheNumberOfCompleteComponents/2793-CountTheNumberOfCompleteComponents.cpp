// Last updated: 7/18/2026, 2:00:11 PM
class Solution {
    void bfs(int src, vector<vector<int>>& adj, vector<int>& vis,
             long long& nodes, long long& degreeSum) {

        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodes++;
            degreeSum += adj[node].size();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                long long nodes = 0;
                long long degreeSum = 0;

                bfs(i, adj, vis, nodes, degreeSum);

                long long edgeCount = degreeSum / 2;

                if (edgeCount == nodes * (nodes - 1) / 2)
                    cnt++;
            }
        }

        return cnt;
    }
};