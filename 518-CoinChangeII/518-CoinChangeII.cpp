// Last updated: 10/19/2026, 3:32:25 PM
1class Solution {
2public:
3    int change(int amount, vector<int>& coins) {
4        vector<unsigned long long> dp(amount + 1, 0); 
5        dp[0] = 1;
6        
7        for (int c : coins) {
8            for (int a = c; a <= amount; a++) {
9                dp[a] += dp[a - c];
10            }
11        }
12        
13        return dp[amount];        
14    }
15};