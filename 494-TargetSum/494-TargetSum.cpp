// Last updated: 10/20/2026, 4:33:12 PM
1class Solution {
2public:
3    int func(int i, vector<int>& nums, int target) {
4        if (i == 0) {
5          int ways = 0 ; 
6          if(target==-nums[0]) ways++;
7          if(target==nums[0]) ways++;
8          return ways;
9        }
10        int plus = func(i - 1, nums, target - nums[i]);
11        int minus = func(i - 1, nums, target + nums[i]);
12        return plus + minus;
13    }
14    int findTargetSumWays(vector<int>& nums, int target) {
15        return func(nums.size() - 1, nums, target);
16    }
17};