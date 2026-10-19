// Last updated: 10/19/2026, 1:29:42 PM
1class Solution {
2public:
3    int lastStoneWeightII(vector<int>& stones) {
4        int n = stones.size();
5        int sum = 0;
6        for (int x : stones)
7            sum += x;
8        int target = sum / 2;
9        vector<int> prev(target + 1, 0);
10        vector<int> curr(target + 1, 0);
11        prev[0] = 0;
12        for (int t = stones[0]; t <= target; t++) {
13            prev[t] = stones[0];
14        }
15        for (int i = 1; i < n; i++) {
16            for (int t = 0; t <= sum / 2; t++) {
17                int nottake = prev[t];
18                int take = 0;
19                if (t >= stones[i])
20                    take = stones[i] + prev[t - stones[i]];
21                curr[t] = max(take, nottake);
22            }
23            prev = curr;
24        }
25        int subset = prev[target];
26        return sum - 2 * subset;
27    }
28};