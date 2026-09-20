// Last updated: 9/20/2026, 3:44:00 PM
1class Solution {
2public:
3    bool isBipartite(vector<vector<int>>& graph) {
4        int n = graph.size();
5        vector<int> color(n, -1);
6        queue<int> q;
7        for (int i = 0; i < n; i++) {
8            if (color[i] == -1) {
9                q.push(i);
10                color[i] = 0;
11                while (!q.empty()) {
12                    int node = q.front();
13                    q.pop();
14                    for (auto it : graph[node]) {
15                        if (color[it] == -1) {
16                            color[it] = 1 - color[node];
17                            q.push(it);
18                        }
19                        else if (color[it] == color[node]) {
20                            return false;
21                        }
22                    }
23                }
24            }
25        }
26        return true;
27    }
28};