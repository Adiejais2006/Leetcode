// Last updated: 9/14/2026, 4:13:42 PM
1class Solution {
2    bool cycle(int node, unordered_set<int>& st, vector<int> adj[],
3               vector<int>& vis) {
4        vis[node] = 1;
5        st.insert(node);
6        for (auto it : adj[node]) {
7            if (!vis[it]) {
8                vis[it] = 1;
9                st.insert(it);
10                if (cycle(it, st, adj, vis))
11                    return true;
12
13            } else if (st.count(it))
14                return true;
15        }
16        st.erase(node);
17        return false;
18    }
19
20public:
21    bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
22        vector<int> adj[numCourses];
23        vector<int> vis(numCourses, 0);
24        unordered_set<int> st;
25        for (auto it : prerequisites) {
26            int u = it[0];
27            int v = it[1];
28            adj[u].push_back(v);
29        }
30        for (int i = 0; i < numCourses; i++) {
31            if (!vis[i] && cycle(i, st, adj, vis))
32                return false;
33        }
34        return true;
35    }
36};