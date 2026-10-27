// Last updated: 10/27/2026, 1:41:08 PM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n = s1.size();
5        int m = s2.size();
6        sort(s1.begin(), s1.end());
7        for (int i = 0; i < m; i++) {
8            string temp = "";
9            for (int j = i; j < i + n && j < m; j++) {
10                temp += s2[j];
11                if (temp.size() == n) {
12                    sort(temp.begin(), temp.end());
13                    if (s1 == temp)
14                        return true;
15                    break;
16                }
17            }
18        }
19        return false;
20    }
21};