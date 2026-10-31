// Last updated: 10/31/2026, 5:08:05 PM
1class Solution {
2
3public:
4    bool canPartition(vector<int>& nums) {
5        int n = nums.size();
6        int sum = 0;
7        for (auto it : nums)
8            sum += it;
9        if (sum % 2 == 1)
10            return 0;
11        vector<int> prev( sum / 2 + 1, 0);
12        vector<int> curr( sum / 2 + 1, 0);
13        prev[0] = 1;
14        if(nums[n-1]==sum/2)
15        prev[sum / 2] = 1;
16        for (int i = n - 2; i >= 0; i--) {
17            for (int t = 0; t <= sum / 2; t++) {
18                int nottake = prev[t];
19                int take = false;
20                if (nums[i] <= t) {
21                    take = prev[t - nums[i]];
22                }
23                curr[t] = take || nottake;
24            }
25            prev = curr;
26        }
27        return prev[sum / 2];
28    }
29};