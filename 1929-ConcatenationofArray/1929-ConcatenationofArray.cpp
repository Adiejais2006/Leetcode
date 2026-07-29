// Last updated: 7/29/2026, 7:46:26 PM
1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4
5        int n = nums.size();
6
7        vector<int> ans(2 * n, 0);
8
9        for (int i = 0; i < n; i++) {
10            ans[i] = nums[i];
11            ans[n + i] = nums[i];
12        }
13        return ans;
14    }
15};