// Last updated: 7/25/2026, 10:52:02 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int max1 = 0, max2 = 0;
5
6        for (; n; n /= 10) {
7            int d = n % 10;
8            if (d >= max1) {
9                max2 = max1;
10                max1 = d;
11            } else if (d > max2) 
12                max2 = d;
13        }
14
15        return max1 * max2;
16    }
17};