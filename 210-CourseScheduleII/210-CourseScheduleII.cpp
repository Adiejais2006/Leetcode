// Last updated: 11/3/2026, 9:19:46 PM
1class Solution {
2    bool topo(int node, vector<int>& ans, vector<int> adj[], vector<int>& vis,
3              stack<int>& st, unordered_set<int>& path) {
4        vis[node] = 1;
5        path.insert(node);
6        for (auto it : adj[node]) {
7            if (!vis[it]) {
8                if (!topo(it, ans, adj, vis, st, path))
9                    return false;
10            } else {
11                if (path.count(it))
12                    return false;
13            }
14        }
15        st.push(node);
16        path.erase(node);
17        return true;
18    }
19
20public:
21    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
22        vector<int> adj[numCourses];
23        for (auto it : prerequisites) {
24            int u = it[0];
25            int v = it[1];
26            adj[v].push_back(u);
27        }
28        vector<int> ans;
29        stack<int> st;
30        unordered_set<int> path;
31        vector<int> vis(numCourses, 0);
32        for (int i = 0; i < numCourses; i++)
33            if (!vis[i])
34                if (!topo(i, ans, adj, vis, st, path))
35                    return {};
36
37        while (!st.empty()) {
38            ans.push_back(st.top());
39            st.pop();
40        }
41        return ans;
42    }
43};