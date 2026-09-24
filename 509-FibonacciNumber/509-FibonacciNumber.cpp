// Last updated: 9/24/2026, 12:07:52 PM
1class Solution {
2
3public:
4    int fib(int n) {
5        if(n==0)return 0;
6        vector<int> dp(n + 1, 0);
7        int a=0;
8        int b=1;
9        for (int i = 2; i <= n; i++) {
10           int curr = a+ b;
11           a=b;
12           b=curr;
13        }
14        return b;
15    }
16};