// Last updated: 9/24/2026, 1:17:49 PM
1class Solution {
2
3public:
4    int minCostClimbingStairs(vector<int>& cost) {
5        int n = cost.size();
6        int prev1 = cost[0];
7        int prev2 = cost[1];
8        for (int ind = 2; ind < n; ind++) {
9            int step1 = cost[ind] + prev2;
10            int step2 = cost[ind] + prev1;
11            int curr = min(step1, step2);
12            prev1 = prev2;
13            prev2 = curr;
14        }
15        return min(prev1, prev2);
16    }
17};