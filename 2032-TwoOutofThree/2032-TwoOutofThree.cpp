// Last updated: 11/2/2026, 11:53:23 PM
1class Solution {
2public:
3    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
4                              vector<int>& nums3) {
5        unordered_set<int> st1, st2, st3;
6        unordered_set<int> ans;
7        for (int x : nums1)
8            st1.insert(x);
9        for (int x : nums2)
10            st2.insert(x);
11        for (int x : nums3)
12            st3.insert(x);
13        for (int x : st1) {
14            if (st2.count(x) || st3.count(x))
15                ans.insert(x);
16        }
17        for (int x : st2) {
18            if (st3.count(x))
19                ans.insert(x);
20        }
21
22        return vector<int>(ans.begin(), ans.end());
23    }
24};