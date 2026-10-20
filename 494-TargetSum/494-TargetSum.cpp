// Last updated: 10/20/2026, 4:22:56 PM
1class Solution {
2    int func(int i, int target, vector<int>& nums) {
3        if (i == 0) {
4            if (target == 0 && nums[0] == 0)
5                return 2;
6            if (target == 0 || target == nums[0])
7                return 1;
8            return 0;
9        }
10        int notpick = func(i - 1, target, nums);
11        int pick = 0;
12        if (target >= nums[i])
13            pick = func(i - 1, target - nums[i], nums);
14        return pick + notpick;
15    }
16public:
17    int findTargetSumWays(vector<int>& nums, int target) {
18        int n = nums.size();
19        int sum = 0;
20        for (int x : nums)
21            sum += x;
22        if (abs(target) > sum)
23            return 0;
24        if ((sum - target) % 2 != 0)
25            return 0;
26        int tar = (sum - target) / 2;
27        return func(n - 1, tar, nums);
28    }
29};