// Last updated: 10/27/2026, 2:19:28 PM
1class Solution {
2
3    class Union {
4    public:
5        vector<int> parent;
6        vector<int> size;
7        Union(int n) {
8            parent.resize(n + 1);
9            size.resize(n + 1, 1);
10            for (int i = 0; i <= n; i++) {
11                parent[i] = i;
12            }
13        }
14        int ulp(int a) {
15            if (a == parent[a])
16                return a;
17            return parent[a] = ulp(parent[a]);
18        }
19        void unionbysize(int a, int b) {
20            int ua = ulp(a);
21            int ub = ulp(b);
22            if (ua == ub)
23                return;
24            if (size[ua] > size[ub]) {
25                size[ua] += size[ub];
26                parent[ub] = ua;
27            } else {
28                size[ub] += size[ua];
29                parent[ua] = ub;
30            }
31        }
32    };
33
34public:
35    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
36        int n = accounts.size();
37        Union ds(n);
38        map<string, int> mpp;
39        for (int i = 0; i < n; i++) {
40            for (int j = 1; j < accounts[i].size(); j++) {
41                string mail = accounts[i][j];
42                if (mpp.find(mail) == mpp.end()) {
43                    mpp[mail] = i;
44                } else
45                    ds.unionbysize(mpp[mail], i);
46            }
47        }
48        vector<vector<string>> mergedmail(n);
49        for (auto it : mpp) {
50            string mail = it.first;
51            int node = ds.ulp(it.second);
52            mergedmail[node].push_back(mail);
53        }
54        vector<vector<string>> ans;
55        for (int i = 0; i < n; i++) {
56            if (mergedmail[i].size() == 0)
57                continue;
58            sort(mergedmail[i].begin(), mergedmail[i].end());
59            vector<string> temp;
60            temp.push_back(accounts[i][0]);
61            for (auto it : mergedmail[i]) {
62                temp.push_back(it);
63            }
64            ans.push_back(temp);
65        }
66        return ans;
67    }
68};