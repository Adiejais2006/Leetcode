// Last updated: 9/30/2026, 4:41:19 PM
1class Solution {
2public:
3    vector<int> maxDepthAfterSplit(auto s) {
4        int n = s.size(); vector<int> res(n);
5        for (int i = 0; i < n; i++)
6            res[i] = (i ^ s[i]) & 1;
7        return res;
8    }
9};