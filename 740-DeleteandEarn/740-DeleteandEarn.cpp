// Last updated: 9/24/2026, 8:51:26 PM
1class Solution {
2
3public:
4    int deleteAndEarn(vector<int>& nums) {
5        int n = nums.size();
6        int mx = *max_element(nums.begin(), nums.end());
7        vector<int> gain(mx + 1, 0);
8        for (int x : nums) {
9            gain[x] += x;
10        }
11        vector<int> dp(mx + 1, 0);
12        dp[0] = gain[0];
13        if(mx>=1)
14        dp[1] = gain[1];
15        for (int i = 2; i <= mx; i++) {
16            int notpick = dp[i - 1];
17            int pick = gain[i] + dp[i - 2];
18            dp[i] = max(pick, notpick);
19        }
20        return dp[mx];
21    }
22};