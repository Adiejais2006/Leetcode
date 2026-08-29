// Last updated: 8/29/2026, 8:00:40 PM
1class Solution {
2public:
3    vector<int> lexicographicallySmallestArray(vector<int>& A, int limit) {
4        vector<int> sorted = A;
5        ranges::sort(sorted);
6        vector<vector<int>> grps;
7        unordered_map<int, int> map;
8        int id = -1;
9
10        for (int i = 0; i < sorted.size(); i++) {
11            if (i == 0 || sorted[i] - sorted[i - 1] > limit) {
12                grps.push_back({});
13                id++;
14            }
15            grps[id].push_back(sorted[i]);
16            map[sorted[i]] = id;
17        }
18
19        vector<int> idx(grps.size(), 0);
20
21        for (int i = 0; i < A.size(); i++) {
22            int cur = map[A[i]];
23            A[i] = grps[cur][idx[cur]];
24            idx[cur]++;
25        }
26
27        return A;
28    }
29};