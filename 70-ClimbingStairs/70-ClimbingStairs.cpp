// Last updated: 9/24/2026, 12:22:15 PM
1class Solution {
2public:
3    int climbStairs(int n) {
4        int prev1 = 1;
5        int prev2 = 1;
6        for (int i = 2; i <= n; i++) {
7            int curr = prev1 + prev2;
8            prev1 = prev2;
9            prev2 = curr;
10        }
11        return prev2;
12    }
13};