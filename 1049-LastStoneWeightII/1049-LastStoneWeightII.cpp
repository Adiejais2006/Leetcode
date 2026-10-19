// Last updated: 10/19/2026, 1:23:32 PM
1class Solution {
2public:
3    int lastStoneWeightII(vector<int>& stones) {
4        int n = stones.size();
5        int sum = 0;
6        for (int x : stones)
7            sum += x;
8        int target = sum / 2;
9        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
10        for (int i = 0; i < n; i++)
11            dp[i][0] = 0;
12        for (int t = stones[0]; t <= target; t++) {
13            dp[0][t] = stones[0];
14        }
15        for (int i = 1; i < n; i++) {
16            for (int t = 0; t <= sum / 2; t++) {
17                int nottake = dp[i - 1][t];
18                int take = 0;
19                if (t >= stones[i])
20                    take = stones[i] + dp[i - 1][t - stones[i]];
21                dp[i][t] = max(take, nottake);
22            }
23        }
24        int subset = dp[n - 1][target];
25        return sum - 2 * subset;
26    }
27};