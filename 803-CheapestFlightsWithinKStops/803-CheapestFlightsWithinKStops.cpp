// Last updated: 7/18/2026, 2:03:22 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int K) {

      vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>q;  // cost , node and steps
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int adjCost = it.second;
                if (cost + adjCost < dist[adjNode] && steps <= K) {
                    dist[adjNode] = cost + adjCost;
                    q.push({steps + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;
        else
            return dist[dst];


    }
};