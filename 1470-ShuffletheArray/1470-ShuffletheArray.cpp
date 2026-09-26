// Last updated: 9/26/2026, 2:44:38 PM
1class Solution {
2public:
3    vector<int> shuffle(vector<int>& nums, int n) {
4        vector<int> res;
5
6        for(int i = 0; i < n; i++) {
7            res.push_back(nums[i]);
8            res.push_back(nums[i+n]);
9        }
10        return res;
11    }
12};