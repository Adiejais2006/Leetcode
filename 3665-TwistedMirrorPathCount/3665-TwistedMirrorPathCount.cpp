// Last updated: 10/31/2026, 2:21:01 PM
1class Solution {
2public:
3    int uniquePaths(vector<vector<int>>& nums) {
4        int n = nums.size(), m = nums[0].size();
5        long long int mod = 1e9 + 7;
6        vector<long long int> dp(m, 0);
7        dp[0] = 1;
8        for(auto &row : nums) {
9            long long int right = 0;
10            for(int j = 0; j < m; j++) {
11                if(row[j] == 1) {
12                    swap(right, dp[j]);
13                }else{
14                    right = dp[j] = (right + dp[j]) % mod;
15                }
16            }
17        }
18        return dp[m-1];
19    }
20};