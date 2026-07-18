// Last updated: 7/18/2026, 1:59:22 PM
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> g(n);

        int l = INT_MAX;
        int r = 0;

        // Build graph, ignoring offline nodes
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (!online[u] || !online[v])
                continue;

            g[u].push_back({v, w});
            l = min(l, w);
            r = max(r, w);
        }

        if (l == INT_MAX) return -1;

        auto check = [&](int mid) {
            vector<long long> dist(n, LLONG_MAX);
            priority_queue<
                pair<long long, int>,
                vector<pair<long long, int>>,
                greater<pair<long long, int>>
            > pq;

            dist[0] = 0;
            pq.push({0, 0});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d != dist[u]) continue;
                if (d > k) continue;
                if (u == n - 1) return true;

                for (auto &[v, w] : g[u]) {
                    if (w < mid) continue;

                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            return false;
        };

        while (l < r) {
            int mid = l + (r - l + 1) / 2;

            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }

        return check(l) ? l : -1;
    }
};