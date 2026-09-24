// Last updated: 9/24/2026, 1:33:32 PM
1class Solution {
2public:
3    int rob(vector<int>& nums) {
4        int n = nums.size();
5        int prev = nums[0];
6        int prev2= 0;
7        for (int i = 1; i < n; i++) {
8            int take = nums[i] + ((i > 1) ? prev2 : 0);
9            int nottake = prev;
10            int cur =  max(take, nottake);
11            prev2=prev;
12            prev =cur;
13        }
14        return prev;
15    }
16};