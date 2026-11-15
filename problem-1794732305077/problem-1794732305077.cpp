// Last updated: 11/15/2026, 2:15:05 PM
1class Solution {
2    bool checker(int i, int j, vector<int> nums) {
3        sort(nums.begin() + i, nums.begin() + j + 1);
4        int d = nums[i + 1] - nums[i];
5        for (int k = i + 2; k <= j; k++) {
6            if (nums[k] - nums[k - 1] != d)
7                return false;
8        }
9        return true;
10    }
11
12public:
13    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
14                                          vector<int>& r) {
15        int n = l.size();
16        vector<bool> ans(n);
17        for (int i = 0; i < n; i++) {
18            ans[i] = checker(l[i], r[i], nums);
19        }
20        return ans;
21    }
22};