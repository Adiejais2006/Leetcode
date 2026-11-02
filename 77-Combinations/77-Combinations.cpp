// Last updated: 11/3/2026, 12:10:02 AM
1class Solution {
2public:
3    vector<vector<int>> ans;
4
5    void solve(int idx, int n, int k, vector<int>& curr) {
6
7        if (curr.size() == k) {
8            ans.push_back(curr);
9            return;
10        }
11
12        for (int i = idx; i <= n; i++) {
13
14            curr.push_back(i);
15
16            solve(i + 1, n, k, curr);
17
18            curr.pop_back();
19        }
20    }
21
22    vector<vector<int>> combine(int n, int k) {
23
24        vector<int> curr;
25
26        solve(1, n, k, curr);
27
28        return ans;
29    }
30};