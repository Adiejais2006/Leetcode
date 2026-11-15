// Last updated: 11/15/2026, 3:10:57 PM
1class Solution {
2public:
3    vector<int> avoidFlood(vector<int>& rains) {
4        int n = rains.size();
5        unordered_map<int, queue<int>> mp;
6        for (int i = 0; i < n; i++) {
7            if (rains[i] > 0) {
8                mp[rains[i]].push(i);
9            }
10        }
11        set<pair<int, int>> st;
12        unordered_set<int> full;
13        vector<int> ans(n, 1);
14        for (int i = 0; i < n; i++) {
15            if (rains[i] > 0) {
16                int lake = rains[i];
17                if (full.count(lake))
18                    return {};
19                full.insert(lake);
20                mp[lake].pop();
21                int nextDay = INT_MAX;
22                if (!mp[lake].empty())
23                    nextDay = mp[lake].front();
24                st.insert({nextDay, lake});
25                ans[i] = -1;
26            } else {
27                if (!st.empty()) {
28                    auto it = st.begin();
29                    int lake = it->second;
30                    ans[i] = lake;
31                    full.erase(lake);
32                    st.erase(it);
33                }
34            }
35        }
36        return ans;
37    }
38};