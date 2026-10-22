// Last updated: 10/22/2026, 1:29:17 PM
1class Solution {
2    bool is(int i, int j, string& s) {
3        while (i < j) {
4            if (s[i++] != s[j--])
5                return false;
6        }
7        return true;
8    }
9
10public:
11    int countSubstrings(string s) {
12        int n = s.size();
13        int cnt = 0;
14        for (int i = 0; i < n; i++) {
15            string a = "";
16            for (int j = i; j < n; j++) {
17                a += s[j];
18                if (is(i, j, s))
19                    cnt++;
20            }
21        }
22        return cnt;
23    }
24};