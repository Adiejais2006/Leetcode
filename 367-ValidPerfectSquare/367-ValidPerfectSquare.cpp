// Last updated: 7/29/2026, 8:04:52 PM
1class Solution {
2public:
3    bool isPerfectSquare(int num) {
4        int l = 2;
5        int r = num;
6        if (num == 1)
7            return 1;
8        while (l <= r) {
9            int mid = l + (r - l) / 2;
10            long long number = (long long)mid * mid;
11            if ((int)number == num)
12                return 1;
13            else if (number > num)
14                r = mid - 1;
15            else
16                l = mid + 1;
17        }
18
19        return 0;
20    }
21};