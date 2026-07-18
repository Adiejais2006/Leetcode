// Last updated: 7/18/2026, 2:05:37 PM
class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& arr) {
        vector<int> adj[N];
        vector<int> indegree(N, 0);
        for (int i = 0; i < arr.size(); i++) {
            int u = arr[i][1];
            int v = arr[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> temp;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            temp.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return temp.size() == N;
    }
};