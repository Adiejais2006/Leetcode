// Last updated: 11/1/2026, 2:37:00 PM
1class Solution {
2public:
3    int arraySign(vector<int>& nums) {
4        int ans = 1;
5        for (auto it : nums) {
6            if (it < 0) {
7                ans *= -1;
8            } else if (it == 0) {
9                return 0;
10            }
11        }
12        return ans;
13    }
14};