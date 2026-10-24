// Last updated: 10/24/2026, 1:26:19 PM
1class Solution {
2public:
3    int countDaysTogether(string a, string b, string c, string d) {
4        return max(0, min(f(b), f(d)) - max(f(a), f(c)) + 1);
5    }
6    int f(auto& s) {
7        int m = (s[0] - '0') * 10 + (s[1] - '0');
8        int q = (s[3] - '0') * 10 + (s[4] - '0');
9
10        return (275 * m) / 9 - 30 - 2 * ((m + 9) / 12) + q;
11    }
12};