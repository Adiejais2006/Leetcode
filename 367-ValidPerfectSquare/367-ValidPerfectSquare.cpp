// Last updated: 7/29/2026, 7:58:37 PM
1class Solution {
2public:
3    bool isPerfectSquare(int num) {
4        for(long long i = 1; i <=num; i++) {
5            if(i*i==num) {
6                return 1;
7            }
8            else if(i*i>num) {
9                break;
10            }
11        }
12        return 0;
13    }
14};