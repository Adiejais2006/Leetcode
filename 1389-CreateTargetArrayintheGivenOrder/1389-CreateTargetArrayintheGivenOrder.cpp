// Last updated: 11/1/2026, 2:48:23 PM
1class Solution {
2public:
3    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
4        int n = nums.size();
5        vector<int> ans;
6        for (int i = 0; i < n; i++) {
7            int ind = index[i];
8            int val = nums[i];
9            ans.insert(ans.begin() + ind ,val);
10        }
11        return ans;
12    }
13};