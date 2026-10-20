// Last updated: 10/20/2026, 4:30:18 PM
1class Solution {
2
3public:
4    int findTargetSumWays(vector<int>& nums, int target) {
5        int n = nums.size();
6        int sum = 0;
7        for (int x : nums)
8            sum += x;
9        if (abs(target) > sum)
10            return 0;
11        if ((sum - target) % 2 != 0)
12            return 0;
13        int tar = (sum - target) / 2;
14        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
15        for (int i = 0; i <= tar; i++) {
16            if (i == 0 && nums[0] == 0)
17                dp[0][i] = 2;
18            else if (i == 0 || i == nums[0])
19                dp[0][i] = 1;
20        }
21        for (int i = 1; i < n; i++) {
22            for (int j = 0; j <= tar; j++) {
23                int notpick = dp[i - 1][j];
24                int pick = 0;
25                if (j >= nums[i])
26                    pick = dp[i - 1][j - nums[i]];
27                dp[i][j] = pick + notpick;
28            }
29        }
30        return dp[n - 1][tar];
31    }
32};