// Last updated: 7/29/2026, 8:23:40 PM
1class Solution {
2public:
3    int addDigits(int num) {
4        while (num >= 10) {
5            int ans = 0;
6            int orig = num; 
7            while (orig != 0) {
8                ans += orig % 10;
9                orig /= 10;
10            }
11            num = ans;
12        }
13        return num;
14    }
15};
16