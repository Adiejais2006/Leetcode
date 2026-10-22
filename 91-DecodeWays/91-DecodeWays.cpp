// Last updated: 10/22/2026, 4:43:39 PM
1class Solution {
2public:
3    int numDecodings(string s) {
4        int n = s.size();
5        int next = 1;
6        int curr = 0;
7        int next2 = 0;
8        for (int i = n - 1; i >= 0; i--) {
9            if (s[i] == '0') {
10                curr = 0;
11                next2 = next;
12                next = curr;
13                continue;
14            }
15            int one = next;
16            int two = 0;
17            if (i + 1 < n) {
18                int a = (s[i] - '0') * 10 + (s[i + 1] - '0');
19                if (a >= 10 && a <= 26) {
20                    two = next2;
21                }
22            }
23            curr = one + two;
24            next2 = next;
25            next = curr;
26        }
27
28        return next;
29    }
30};