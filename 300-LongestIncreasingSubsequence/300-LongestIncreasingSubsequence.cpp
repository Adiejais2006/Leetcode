// Last updated: 10/20/2026, 8:29:29 PM
1
2class Solution {
3public:
4    int lengthOfLIS(vector<int>& nums) {
5        int n = nums.size();
6        vector<int> pre(n + 1, 0);
7        vector<int> curr(n + 1, 0);
8        for (int i = 0; i < n; i++) {
9            for (int prev = -1; prev < n; prev++) {
10                int notpick = (i > 0) ? pre[prev + 1] : 0;
11                int pick = 0;
12                if (prev == -1 || nums[i] < nums[prev]) {
13                    pick = 1 + ((i > 0) ? pre[i + 1] : 0);
14                }
15              curr[prev + 1] = max(pick, notpick);
16            }
17            pre=curr;
18        }
19
20        return pre[0];
21    }
22};
23