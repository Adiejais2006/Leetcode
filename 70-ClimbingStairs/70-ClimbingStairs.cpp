// Last updated: 9/24/2026, 12:15:20 PM
1class Solution { int func(int  n , vector<int>&dp){
2        if(n==0) return 1;
3        if(n<0) return 0 ;
4        if(dp[n]!=-1) return dp[n];
5        int left = func(n-1,dp);
6        int right = func(n-2,dp);
7        return dp[n] = left + right;
8    }
9public:
10    int climbStairs(int n) {
11        vector<int> dp(n+1,-1);
12        return func(n ,dp);
13    }
14};