// Last updated: 11/15/2026, 3:01:19 PM
1class Solution {
2public:
3    vector<int> avoidFlood(vector<int>& rains) {
4        int n = rains.size();
5        vector<int> ans(rains.size(), 1);
6        set<int> st;
7        unordered_map<int, int> mp;
8        for (int i = 0; i < n; i++) {
9            if (rains[i] == 0) {
10                st.insert(i);
11            } else {
12                ans[i] = -1;
13                if (mp.count(rains[i])) {
14                    auto it = st.lower_bound(mp[rains[i]]);
15                    if (it == st.end()) {
16                        return {};
17                    }
18                    ans[*it] = rains[i];
19                    st.erase(it);
20                }
21                mp[rains[i]] = i;
22            }
23        }
24        return ans;
25    }
26};