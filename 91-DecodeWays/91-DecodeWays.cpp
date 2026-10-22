// Last updated: 10/22/2026, 4:33:39 PM
1class Solution {
2    int func(int i , string s, vector<int> &dp){
3        if(i>s.size())return 0 ;
4        if(i==s.size())return 1 ; 
5        if(s[i]=='0')return 0 ;
6        if(dp[i]!=-1)return dp[i];
7        int one = func(i+1 ,s,dp);
8        int two = 0 ; 
9        if(i+1<s.size()){
10            int a = (s[i]-'0')*10 + (s[i+1]-'0');
11            if(a<=26)  two = func(i+2 , s,dp);
12        }
13        return dp[i] =  one + two ;
14    }   
15public:
16    int numDecodings(string s) {
17        int n = s.size();
18        vector<int> dp(n+1 ,-1);
19        return func(0 ,s,dp);
20    }   
21};