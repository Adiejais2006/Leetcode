// Last updated: 10/18/2026, 7:18:43 PM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n = s1.size(); // tofind
5        int m = s2.size(); // fromfind
6        sort(s1.begin(), s1.end());
7        for (int i = 0; i < m - n + 1; i++) {
8            string ans = "";
9            for (int j = i; j < i + n; j++) {
10                ans += s2[j];
11                if (ans.size() == n)
12                    sort(ans.begin(), ans.end());
13                if (ans == s1)
14                    return true;
15            }
16        }
17        return false;
18    }
19};