// Last updated: 8/5/2026, 4:06:02 PM
1class Solution {
2public:
3    vector<int> remainingMethods(int n, int k,
4                                 vector<vector<int>>& invocations) {
5        vector<vector<int>> adj(n);
6        for (auto &it : invocations) {
7            adj[it[0]].push_back(it[1]);
8        }
9        vector<int> vis(n, 0);
10        queue<int> q;
11        q.push(k);
12        vis[k] = 1;
13        while (!q.empty()) {
14            int node = q.front();
15            q.pop();
16            for (int nxt : adj[node]) {
17                if (!vis[nxt]) {
18                    vis[nxt] = 1;
19                    q.push(nxt);
20                }
21            }
22        }
23        for (auto &it : invocations) {
24            if (!vis[it[0]] && vis[it[1]]) {
25                vector<int> ans;
26                for (int i = 0; i < n; i++)
27                    ans.push_back(i);
28                return ans;
29            }
30        }
31        vector<int> ans;
32        for (int i = 0; i < n; i++) {
33            if (!vis[i])
34                ans.push_back(i);
35        }
36
37        return ans;
38    }
39};