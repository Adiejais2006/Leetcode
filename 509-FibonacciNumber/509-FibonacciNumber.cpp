// Last updated: 9/24/2026, 12:08:47 PM
1class Solution {
2
3public:
4    int fib(int n) {
5        if(n==0)return 0;
6        vector<int> dp(n + 1, 0);
7        int prev1=0;
8        int prev2=1;
9        for (int i = 2; i <= n; i++) {
10           int curr = prev1+ prev2;
11           prev1=prev2;
12           prev2=curr;
13        }
14        return prev2;
15    }
16};