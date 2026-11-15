// Last updated: 11/15/2026, 3:19:35 PM
1class Solution {
2public:
3    vector<int> avoidFlood(vector<int>& rains) {
4        int n = rains.size();
5        vector<int> ans(n, 1);
6        unordered_map<int, int> lastRain;
7        set<int> dryDays;
8        for (int i = 0; i < n; i++) {
9            if (rains[i] == 0) {
10                dryDays.insert(i);
11            }
12            else {
13                int lake = rains[i];
14                if (lastRain.count(lake)) {
15                    auto it = dryDays.upper_bound(lastRain[lake]);
16                    if (it == dryDays.end())
17                        return {};
18                    ans[*it] = lake;
19                    dryDays.erase(it);
20                }
21                lastRain[lake] = i;
22                ans[i] = -1;
23            }
24        }
25        return ans;
26    }
27};