// Last updated: 7/18/2026, 1:59:04 PM
class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges,
                         vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        function<long long(int)> dfs = [&](int node) {
            if (adj[node].empty())
                return (long long)baseTime[node];
            long long mini = LLONG_MAX;
            long long maxi = LLONG_MIN;
            for (auto child : adj[node]) {
                long long curr = dfs(child);
                mini = min(mini, curr);
                maxi = max(maxi, curr);
            }
            long long ownDuration = (maxi - mini) + baseTime[node];
            return maxi + ownDuration;
        };
        return dfs(0);
    }
};