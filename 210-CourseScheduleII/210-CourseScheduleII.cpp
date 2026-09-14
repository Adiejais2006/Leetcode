// Last updated: 9/14/2026, 4:55:17 PM
1class Solution {
2public:
3    vector<int> findOrder(int n, vector<vector<int>>& nums) {
4        vector<int> adj[n];
5        for (auto it : nums) {
6            int u = it[1];
7            int v = it[0];
8            adj[u].push_back(v);
9        }
10        vector<int> indegree(n, 0);
11        for (int i = 0; i < n; i++) {
12            for (auto it : adj[i]) {
13                indegree[it]++;
14            }
15        }
16        queue<int> q;
17        for (int i = 0; i < n; i++)
18            if (indegree[i] == 0)
19                q.push(i);
20        vector<int> ans;
21        while (!q.empty()) {
22            auto node = q.front();
23            q.pop();
24            ans.push_back(node);
25            for (auto it : adj[node]) {
26                if (indegree[it] > 0)
27                    indegree[it]--;
28                if (indegree[it] == 0)
29                    q.push(it);
30            }
31        }
32        if(ans.size()!=n) return {};
33        return ans;
34    }
35};