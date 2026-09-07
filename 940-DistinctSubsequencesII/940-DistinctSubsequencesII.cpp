// Last updated: 9/7/2026, 3:28:01 PM
1class Solution {
2public:
3    int distinctSubseqII(string s) {
4        int n = s.size();
5        int MOD = 1e9 + 7;
6        vector<int> dp(n, 1);
7        int result = 0;
8        for(int i = 0; i < n; i++){
9            for(int j = 0; j < i; j++){
10                if(s[i] != s[j]) {
11                    dp[i] = (dp[i] + dp[j]) % MOD;
12                }
13            }
14            result = (result + dp[i]) % MOD;
15        }
16        return result;
17    }
18};