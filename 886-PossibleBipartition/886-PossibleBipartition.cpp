// Last updated: 9/20/2026, 4:03:52 PM
1class Solution
2{
3    bool bfs(int src, vector<int> &color, vector<int> adj[])
4    {
5        color[src] = 1;
6        queue<int> q;
7        q.push(src);
8        while (!q.empty())
9        {
10            auto node = q.front();
11            q.pop();
12            for (auto it: adj[node])
13            {
14                if (color[it] == color[node])
15                    return false;
16                else if (color[it] == -1)
17                {
18                    color[it] = 1 - color[node];
19                    q.push(it);
20                }
21            }
22        }
23        return true;
24    }
25
26    public:
27        bool possibleBipartition(int n, vector<vector < int>> &dislikes)
28        {
29            vector<int> adj[n+1];
30            for (auto it: dislikes)
31            {
32                int u = it[0];
33                int v = it[1];
34                adj[u].push_back(v);
35                adj[v].push_back(u);
36            }
37            vector<int> color(n+1, -1);
38            for (int i = 0; i <= n; i++)
39            {
40                if (color[i] == -1)
41                {
42                    if (!bfs(i, color, adj))
43                        return false;
44                }
45            }
46            return true;
47        }
48};