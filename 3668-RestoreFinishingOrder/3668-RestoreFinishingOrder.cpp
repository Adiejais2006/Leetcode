// Last updated: 7/19/2026, 1:44:46 PM
1class Solution {
2public:
3    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
4        vector<int> ans;
5        unordered_map<int, int> mpp;
6        for (auto it : friends) {
7            mpp[it]++;
8        }
9
10        for (auto it : order) {
11            if (mpp.count(it))
12                ans.push_back(it);
13        }
14        return ans;
15    }
16};