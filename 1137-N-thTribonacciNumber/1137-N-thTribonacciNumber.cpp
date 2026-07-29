// Last updated: 7/29/2026, 8:16:59 PM
1class Solution {
2public:
3    int tribonacci(int n) {
4        if (n == 0)
5            return 0;
6        if (n == 1)
7            return 1;
8        if (n == 2)
9            return 1;
10        int a = 0;
11        int b = 1;
12        int c = 1;
13        int ans = -1;
14        while (n - 2 != 0) {
15            int next = a + b + c;
16            a = b;
17            b = c;
18            c = next;
19            ans = next;
20            n--;
21        }
22        return ans;
23    }
24};