// Last updated: 11/6/2026, 4:10:58 PM
1class Solution {
2public:
3    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
4        sort(logs.begin(), logs.end(),
5             [](auto &a, auto &b) {
6                 return a[1] < b[1];
7             });
8
9        vector<pair<int, int>> q;
10
11        for (int i = 0; i < queries.size(); i++) {
12            q.push_back({queries[i], i});
13        }
14
15        sort(q.begin(), q.end());
16
17        vector<int> ans(queries.size());
18        unordered_map<int, int> freq;
19
20        int left = 0, right = 0;
21        int active = 0;
22
23        for (auto &[time, idx] : q) {
24            while (right < logs.size() && logs[right][1] <= time) {
25                if (++freq[logs[right][0]] == 1) active++;
26                right++;
27            }
28
29            while (left < right && logs[left][1] < time - x) {
30                if (--freq[logs[left][0]] == 0) active--;
31                left++;
32            }
33
34            ans[idx] = n - active;
35        }
36
37        return ans;
38    }
39};