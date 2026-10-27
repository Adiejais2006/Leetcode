// Last updated: 10/27/2026, 1:39:47 PM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n = s1.size();
5        int m = s2.size();
6        for (int i = 0; i < m; i++) {
7            string temp = "";
8            for (int j = i; j < i + n && j < m; j++) {
9                temp += s2[j];
10                if (temp.size() == n) {
11                    sort(temp.begin(), temp.end());
12                    sort(s1.begin(), s1.end());
13                    if (s1 == temp)
14                        return true;
15                }
16            }
17        }
18        return false;
19    }
20};