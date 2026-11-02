// Last updated: 11/2/2026, 11:46:11 PM
1class Solution {
2public:
3    int maximumDifference(vector<int>& nums) {
4        int n = nums.size(), mini = nums[0], ans = -1;
5        for (int i = 1; i < n; i++) {
6            if (nums[i] > mini) {
7                ans = max(ans, nums[i] - mini);
8            }
9            mini = min(mini, nums[i]);
10        }
11
12        return ans;
13    }
14};
15