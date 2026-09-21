// Last updated: 9/21/2026, 6:50:43 PM
1class Solution {
2public:
3    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
4        if(n==1)return {0};
5        vector<int> adj[n];
6        vector<int> degree(n, 0);
7        for (auto it : edges) {
8            int u = it[0];
9            int v = it[1];
10            adj[u].push_back(v);
11            adj[v].push_back(u);
12            degree[u]++;
13            degree[v]++;
14        }
15        queue<int> q;
16        for (int i = 0; i < n; i++) {
17            if (degree[i] == 1) {
18                q.push(i);
19            }
20        }
21        int r = n;
22        while (r > 2) {
23            int size = q.size();
24            r -= size;
25            while (size--) {
26                auto leaf = q.front();
27                q.pop();
28                for (auto it : adj[leaf]) {
29                    degree[it]--;
30                    if (degree[it] == 1)
31                        q.push(it);
32                }
33            }
34        }
35        vector<int> ans;
36        while (!q.empty()) {
37            ans.push_back(q.front());
38            q.pop();
39        }
40        return ans;
41    }
42};