// Last updated: 7/18/2026, 2:00:18 PM
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        vector<vector<int>> adj(n);
        vector<int> deg(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 && coins[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            deg[u]--;

            for (int v : adj[u]) {
                if (deg[v] > 0) {
                    deg[v]--;
                    if (deg[v] == 1 && coins[v] == 0)
                        q.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1)
                q.push(i);
        }

        int rounds = 2;

        while (rounds--) {
            int sz = q.size();

            while (sz--) {
                int u = q.front();
                q.pop();

                deg[u]--;

                for (int v : adj[u]) {
                    if (deg[v] > 0) {
                        deg[v]--;
                        if (deg[v] == 1)
                            q.push(v);
                    }
                }
            }
        }

        int remaining = 0;

        for (auto &e : edges) {
            if (deg[e[0]] > 0 && deg[e[1]] > 0)
                remaining++;
        }

        return remaining * 2;
    }
};