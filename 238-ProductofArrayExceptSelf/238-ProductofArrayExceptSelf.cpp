// Last updated: 7/24/2026, 12:27:53 AM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n, 1);
6        for (int i = 1; i < n; i++) {
7            ans[i] = ans[i - 1] * nums[i - 1];
8        }
9        int suffix = 1;
10        for (int i = n - 1; i >= 0; i--) {
11            ans[i] *= suffix;
12            suffix *= nums[i];
13        }
14        return ans;
15    }
16};
17