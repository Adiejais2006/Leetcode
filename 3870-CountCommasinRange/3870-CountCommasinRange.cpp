// Last updated: 9/8/2026, 6:16:16 PM
1class Solution {
2public:
3    int countCommas(int n) {
4        int count = 0;
5        for (int i = 1; i <= n; i++) {
6            if (i >= 1000) {
7                count++;
8            }
9        }
10
11        return count;
12    }
13};