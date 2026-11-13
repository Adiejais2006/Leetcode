// Last updated: 11/13/2026, 2:10:05 PM
1class Solution {
2public:
3    int longestArithSeqLength(vector<int>& nums) {
4        int n = nums.size();
5        int ans = 2;
6        vector<unordered_map<int, int>> dp(n); // har index pr har differnce ke liye max lengt stoer kr rahe hain
7        for (int i = 0; i < n; i++) {
8            for (int j = 0; j < i; j++) {
9                int diff = nums[i] - nums[j];
10                int len = 2;
11                if (dp[j].count(diff)) { // piche j index tak kya koi diff waala length exist krta hai ya nahhi 
12                   dp[i][diff] = dp[j][diff] + 1;
13                }
14                else {
15                    dp[i][diff]=2;
16                }
17                ans = max(ans, dp[i][diff]);
18            }
19        }
20        return ans;
21    }
22};