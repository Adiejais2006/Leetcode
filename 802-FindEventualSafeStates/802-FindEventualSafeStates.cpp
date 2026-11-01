// Last updated: 11/1/2026, 4:25:07 PM
1class Solution {
2    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph,
3             vector<int>& safe) {
4
5        vis[node] = 1;
6        for (auto it : graph[node]) {
7            if (!vis[node]) {
8                if (!dfs(it, vis, graph, safe))
9                    return false;
10            }
11            else {
12                if(!safe[it])return false;
13            }
14        }
15        safe[node] = 1  ;
16        return true;
17    }
18
19public:
20    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
21        int n = graph.size();
22        vector<int> vis(n, 0);
23        vector<int> safe(n, 0);
24        for (int i = 0; i < n; i++) {
25            if (graph[i].empty()) {
26                safe[i] = 1;
27                vis[i] = 1;
28            }
29        }
30        vector<int> ans;
31        for (int i = 0; i < n; i++) {
32            if (!vis[i])
33                dfs(i, vis, graph, safe);
34        }
35        for (int i = 0; i < n; i++) {
36            if (safe[i])
37                ans.push_back(i);
38        }
39        return ans;
40    }
41};