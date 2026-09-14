// Last updated: 9/14/2026, 2:57:45 PM
1class Solution {
2    void dfs(int node, vector<int>& vis, vector<int> adj[]) {
3        if (vis[node])
4            return;
5        vis[node] = 1;
6        for (auto it : adj[node]) {
7            if (!vis[it]) {
8                dfs(it, vis, adj);
9            }
10        }
11    }
12
13public:
14    int findCircleNum(vector<vector<int>>& nums) {
15        int n = nums.size();
16        int m = nums[0].size();
17        int cnt = 0;
18        vector<int> vis(n, 0);
19        vector<int> adj[n];
20        for (int i = 0; i < n; i++) {
21            for (int j = 0; j < m; j++) {
22                if (nums[i][j] == 1 && i != j) {
23                    adj[i].push_back(j);
24                }
25            }
26        }
27        for (int i = 0; i < n; i++) {
28            if (!vis[i]) {
29                dfs(i, vis, adj);
30                cnt++;
31            }
32        }
33        return cnt;
34    }
35};