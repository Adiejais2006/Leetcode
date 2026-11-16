// Last updated: 11/16/2026, 5:53:25 PM
1class Solution {
2    void func(int node, int end, vector<int>& vis, vector<vector<int>>& ans,
3              vector<vector<int>>& graph, vector<int> temp) {
4        vis[node] = 1;
5        temp.push_back(node);
6        if (node == end) {
7            ans.push_back(temp);
8        }
9        for (auto it : graph[node]) {
10            if (!vis[it]) {
11                func(it, end, vis, ans, graph, temp);
12            }
13        }
14         temp.pop_back();
15         vis[node] = 0;
16    }
17
18public:
19    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
20        int n = graph.size();
21        vector<vector<int>> ans;
22        vector<int> vis(n, 0);
23        vector<int> temp;
24        func(0, n - 1, vis, ans, graph, temp);
25         return ans;
26    }
27};