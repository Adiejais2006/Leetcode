// Last updated: 11/9/2026, 5:22:48 PM
1class Solution {
2public:
3    vector<string> findItinerary(vector<vector<string>>& tickets) {
4        unordered_map<string, int> id;
5        vector<string> airport;
6        int cnt = 0;
7        auto getId = [&](const string& s) {
8            if (!id.count(s)) {
9                id[s] = cnt++;
10                airport.push_back(s);
11            }
12            return id[s];
13        };
14        for (auto& t : tickets) {
15            getId(t[0]);
16            getId(t[1]);
17        }
18        vector<vector<int>> adj(cnt);
19        for (auto& t : tickets) {
20            int u = id[t[0]];
21            int v = id[t[1]];
22            adj[u].push_back(v);
23        }
24        for (auto& v : adj) {
25            sort(v.begin(), v.end(), [&](int a, int b) {
26                return airport[a] > airport[b];
27            });
28        }
29
30        vector<int> path;
31        function<void(int)> dfs = [&](int node) {
32            while (!adj[node].empty()) {
33                int next = adj[node].back();
34                adj[node].pop_back();
35
36                dfs(next);
37            }
38            path.push_back(node);
39        };
40        dfs(id["JFK"]);
41        reverse(path.begin(), path.end());
42        vector<string> ans;
43        for (int x : path) {
44            ans.push_back(airport[x]);
45        }
46        return ans;
47    }
48};