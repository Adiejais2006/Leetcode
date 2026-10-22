// Last updated: 10/22/2026, 9:30:57 PM
1
2class Solution {
3    bool func(int i, int j, string& s, string& p) {
4        if (j == p.size())
5            return i == s.size();
6        bool firstMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');
7        if (j + 1 < p.size() && p[j + 1] == '*') {
8            return func(i, j + 2, s, p) || (firstMatch && func(i + 1, j, s, p));
9        }
10        if (firstMatch)
11            return func(i + 1, j + 1, s, p);
12        return false;
13    }
14
15public:
16    bool isMatch(string s, string p) { return func(0, 0, s, p); }
17};
18