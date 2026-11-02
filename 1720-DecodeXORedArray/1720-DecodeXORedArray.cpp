// Last updated: 11/2/2026, 11:59:50 PM
1class Solution {
2public:
3    vector<int> decode(vector<int>& encoded, int first) {
4        int n = encoded.size();
5        vector<int> ans(n + 1);
6        ans[0] = first;
7        for (int i = 1; i < n + 1; i++) {
8            ans[i] = encoded[i - 1] ^ ans[i - 1];
9        }
10        return ans;
11    }
12};