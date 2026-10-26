// Last updated: 10/26/2026, 1:55:16 PM
1class Solution {
2   int func(vector<int>& nums, int k) {
3        if (k < 0)
4            return 0;
5        int n = nums.size();
6        long long ans = 0;
7        int l = 0;
8        int r = 0;
9       int sum = 0;
10        while (r < n) {
11            sum += nums[r];
12            while (sum > k) {
13                sum -= nums[l];
14                l++;
15            }
16            if (sum <= k) {
17                ans += (r - l + 1);
18            }
19            r++;
20        }
21        return ans;
22    }
23
24public:
25    int numSubarraysWithSum(vector<int>& nums, int goal) {
26        return func(nums, goal) - func(nums, goal - 1);
27    }
28};