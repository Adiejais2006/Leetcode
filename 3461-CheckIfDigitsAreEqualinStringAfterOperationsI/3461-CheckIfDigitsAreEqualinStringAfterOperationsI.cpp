// Last updated: 11/6/2026, 4:25:11 PM
1class Solution {
2public:
3    bool hasSameDigits(string s) {
4        int n = s.size();
5        while (s.size() > 2) {
6            string ans = "";
7            for (int i = 1; i < s.size(); i++) {
8                int a = ((s[i] - '0') + (s[i - 1] - '0')) % 10;
9                ans += a;
10            }
11            s = ans;
12        }
13
14        return s[0] == s[1];
15    }
16};