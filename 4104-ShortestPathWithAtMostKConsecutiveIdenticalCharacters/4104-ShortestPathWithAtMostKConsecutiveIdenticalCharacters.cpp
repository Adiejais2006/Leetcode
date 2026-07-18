// Last updated: 7/18/2026, 1:59:03 PM
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        vector<vector<int>> dist(
            n, vector<int>(k + 1, INT_MAX)); // node and streak
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        dist[0][1] = 0;
        pq.push({0, {0, 1}}); // cost node and streak

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int cost = it.first;
            int node = it.second.first;
            int streak = it.second.second;
           
            for (auto nodes : adj[node]) {
                int adjNode = nodes.first;
                int edgWt = nodes.second;
                if (labels[node] == labels[adjNode]) {
                    int newStreak = streak + 1;
                    if (newStreak > k)
                        continue;
                    if (cost + edgWt < dist[adjNode][newStreak]) {
                        dist[adjNode][newStreak] = cost + edgWt;
                        pq.push({cost + edgWt, {adjNode, newStreak}});
                    }
                } else {
                    int newStreak = 1;
                    if (cost + edgWt < dist[adjNode][newStreak]) {
                        dist[adjNode][newStreak] = cost + edgWt;
                        pq.push({cost + edgWt, {adjNode, newStreak}});
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int s = 1; s <= k; s++) {
            ans = min(ans, dist[n - 1][s]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};