// Last updated: 10/21/2026, 12:58:22 PM
1class Solution {
2public:
3    int minOperations(auto& s) {
4        int n = s.length();
5        char mn = s[0], mx = s[0];
6        bool isSorted = 1;
7        for (int i = 1; i < n; i++) {
8            if (s[i] < s[i - 1]) isSorted = 0;
9            mn = min(mn, s[i]);
10            mx = max(mx, s[i]);
11        }
12        if (isSorted) return 0;
13        if (n == 2) return -1;
14        if (s.front() == mn || s.back() == mx)
15            return 1;
16        for (int i = 1; i < n - 1; i++)
17            if (s[i] == mn || s[i] == mx)
18                return 2;
19        return 3;
20    }
21};