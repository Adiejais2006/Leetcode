// Last updated: 10/18/2026, 2:45:40 PM
1class Solution {
2    int func(int i, int j, string &s1, string &s2,  vector<vector<int>> &dp) {
3        if(i<0 || j <0) return 0 ;
4        if(dp[i][j]!=-1)return dp[i][j];
5        if (s1[i] == s2[j]) {
6            return 1 + func(i - 1, j - 1, s1, s2,dp);
7        } else {
8            int skipleft = func(i - 1, j, s1, s2,dp);
9            int skipright = func(i , j-1, s1, s2,dp);
10            return dp[i][j] =  max(skipleft, skipright);
11        }
12    }
13
14public:
15    int longestCommonSubsequence(string text1, string text2) {
16        int n = text1.size();
17        int m = text2.size();
18        vector<vector<int>> dp(n , vector<int>(m,-1));
19        return func(n-1,m-1,text1,text2,dp);
20    }
21};