// Last updated: 7/18/2026, 5:01:13 PM
1class Solution {
2public:
3    int trap(vector<int>& nums) {
4        int n = nums.size();
5        int lmax = 0;
6        int rmax = 0;
7        int l = 0;
8        int r = n - 1;
9        int ans = 0;
10        while (l <= r) {
11            if (lmax >= rmax) {
12                rmax = max(rmax, nums[r]);
13                ans += rmax - nums[r];
14                r--;
15            } else {
16                lmax = max(lmax, nums[l]);
17                ans += lmax - nums[l];
18                l++;
19            }
20        }
21        return ans;
22    }
23};