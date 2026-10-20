// Last updated: 10/20/2026, 8:04:28 PM
1class Solution {
2public:
3    int lengthOfLIS(vector<int>& nums) {
4         int n = nums.size();
5        vector<int> before(n + 1, 0);
6        vector<int> curr(n + 1, 0);
7        for (int ind = n - 1; ind >= 0; ind--) {
8            for (int pind = ind - 1; pind >= -1; pind--) {
9                int notpick = before[pind + 1];
10                int pick = 0;
11                if (pind == -1 || nums[ind] > nums[pind])
12                    pick = 1 + before[ind + 1];
13               curr[pind + 1] = max(pick, notpick);
14            }
15            before = curr;
16        }
17        return before[0];
18    }
19};