// Last updated: 7/29/2026, 7:46:30 PM
1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(2 * n, 0);
6        for (int i = 0; i < n; i++) {
7            ans[i] = nums[i];
8            ans[n + i] = nums[i];
9        }
10        return ans;
11    }
12};