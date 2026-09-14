// Last updated: 9/14/2026, 1:27:28 PM
1class Solution {
2public:
3    long long coloredCells(int n) {
4
5        if(n==1) return 1;
6        long long N = n;
7
8        long long  ans = ((N*2)-1)*((N*2)-1) - (4*(N*(N-1)/2));
9        return ans;
10        
11    }
12};