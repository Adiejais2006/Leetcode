// Last updated: 10/27/2026, 1:18:50 PM
1class Solution {
2public:
3    int findLengthOfLCIS(vector<int>& nums) {
4        int ans = 1;
5        int prev = nums[0];
6        int len = 1;
7        for (int i = 1; i < nums.size(); i++) {
8            if (nums[i] > prev) {
9                len++;
10                ans = max(len, ans);
11            } else {
12                len = 1;
13            }
14            prev = nums[i];
15        }
16        return ans;
17    }
18};