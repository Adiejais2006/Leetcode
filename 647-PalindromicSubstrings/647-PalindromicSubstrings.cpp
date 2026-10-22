// Last updated: 10/22/2026, 1:29:39 PM
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
15            for (int j = i; j < n; j++) {
16                if (is(i, j, s))
17                    cnt++;
18            }
19        }
20        return cnt;
21    }
22};