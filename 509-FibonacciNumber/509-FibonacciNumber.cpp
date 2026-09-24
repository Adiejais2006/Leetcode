// Last updated: 9/24/2026, 12:02:23 PM
1class Solution {
2    int func(int n){
3        if(n==0)return 0;
4        if(n==1) return 1;
5        return func(n-1) + func(n-2);
6    }
7public:
8    int fib(int n) {
9        return func(n);
10    }
11};