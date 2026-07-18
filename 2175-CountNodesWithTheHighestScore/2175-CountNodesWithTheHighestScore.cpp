// Last updated: 7/18/2026, 2:01:06 PM
class Solution {
public:
    vector<vector<int>> adj;
    long long mx = 0;
    int cnt = 0;
    int n;

    int dfs(int node) {
        long long score = 1;
        int size = 1;

        for (int child : adj[node]) {
            int sub = dfs(child);
            size += sub;
            score *= sub;
        }

        int rem = n - size;
        if (rem > 0) score *= rem;

        if (score > mx) {
            mx = score;
            cnt = 1;
        } else if (score == mx) {
            cnt++;
        }

        return size;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        adj.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parents[i]].push_back(i);
        }

        dfs(0);
        return cnt;
    }
};