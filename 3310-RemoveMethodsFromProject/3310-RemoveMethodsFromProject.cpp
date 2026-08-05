// Last updated: 8/5/2026, 4:04:45 PM
1class Solution {
2public:
3    vector<int> remainingMethods(int n, int k,
4                                 vector<vector<int>>& invocations) {
5        vector<int> ans;
6        vector<int> adj[n];
7        for (auto it : invocations) {
8            int u = it[0];
9            int v = it[1];
10            adj[u].push_back(v);
11        }
12        set<int> suspicious;
13        vector<int> vis(n, 0);
14        queue<int> q;
15        vis[k] = 1;
16        q.push(k);
17        while (!q.empty()) {
18            auto node = q.front();
19            q.pop();
20            suspicious.insert(node);
21            for (auto it : adj[node]) {
22                if (!vis[it]) {
23                    vis[it] = 1;
24                    q.push(it);
25                }
26            }
27        }
28        bool notPossible = false;
29        for (auto it : invocations) {
30            if (!suspicious.count(it[0]) && suspicious.count(it[1])) {
31                notPossible = true;
32                break;
33            } 
34        }
35        if (notPossible) {
36            vector<int> a;
37            for (int i = 0; i < n; i++)
38                a.push_back(i);
39            return a;
40        }
41
42        for(int i = 0 ; i<n ; i++){
43            if(!suspicious.count(i)) ans.push_back(i);
44        }
45
46        return ans;
47    }
48};