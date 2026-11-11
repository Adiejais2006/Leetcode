// Last updated: 11/11/2026, 1:38:46 PM
1class Solution {
2public:
3    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
4        long long min, max, ans;
5        min = fmin(need1, need2);
6        max = fmax(need1, need2);
7        ans = (long long) need1 * cost1 + (long long) need2 * cost2;
8        ans  = fmin(ans, (long long)min * costBoth + (long long) (need1 - min) * cost1 + (long long) (need2 - min) * cost2);
9        ans = fmin(ans, (long long) max * costBoth);
10        return ans;
11    }
12};