// Last updated: 9/9/2026, 1:07:29 PM
1class Solution {
2public:
3    string reverseWords(string s) {
4        int n = s.size();
5        int l = 0, r = 0;
6        reverse(s.begin(), s.end());
7        int i = 0;
8        while (i < n) {
9            while (i < n && s[i] == ' ')
10                i++;
11            if (i == n)
12                break;
13            l = r;
14            while (i < n && s[i] != ' ') {
15                s[r++] = s[i++];
16            }
17            reverse(s.begin() + l, s.begin() + r);
18            while (i < n && s[i] == ' ')
19                i++;
20            if (i < n)
21                s[r++] = ' ';
22        }
23        s.resize(r);
24        return s;
25    }
26};