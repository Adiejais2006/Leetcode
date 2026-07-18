// Last updated: 7/18/2026, 2:01:17 PM
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         long long mod = 1e9 + 7;
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<long long> dist(n, 1e18);
        vector<long long> cnt(n, 0);
        dist[0] = 0;
        cnt[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;           // weight and node
        q.push({0, 0});  // weight and node

        while (!q.empty()) {
            auto it = q.top();
            q.pop();
             long long node = it.second;
             long long d = it.first;
            
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    cnt[adjNode] = cnt[node];
                    q.push({dist[adjNode], adjNode});
                } else if (dist[adjNode] == d + wt) {
                    cnt[adjNode] = (cnt[adjNode] + cnt[node]) % mod;
                }
            }
        }
        return cnt[n - 1] % mod;
    }
};