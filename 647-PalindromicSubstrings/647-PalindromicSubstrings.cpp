// Last updated: 10/22/2026, 1:42:46 PM
1class Solution {
2
3    bool isPal(int i, int j, string &s) {
4        if (i >= j)
5            return 1;
6        if (s[i] == s[j]) {
7            return isPal(i + 1, j - 1, s);
8        }
9        return 0;
10    }
11
12public:
13    int countSubstrings(string s) {
14        int n = s.size();
15        int cnt = 0;
16        for (int i = 0; i < n; i++) {
17            for (int j = i; j < n; j++) {
18                if (isPal(i, j, s))
19                    cnt++;
20            }
21        }
22        return cnt;
23    }
24};