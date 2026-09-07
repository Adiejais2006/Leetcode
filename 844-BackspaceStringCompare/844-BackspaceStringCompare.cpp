// Last updated: 9/8/2026, 12:49:19 AM
1class Solution {
2public:
3    bool backspaceCompare(string s, string t) {
4        stack<char> s1;
5        stack<char> s2;
6
7        for (auto it : s) {
8            if (it == '#') {
9                if (!s1.empty()) s1.pop(); 
10            } else {
11                s1.push(it);
12            }
13        }
14
15        for (auto it : t) {
16            if (it == '#') {
17                if (!s2.empty()) s2.pop(); 
18            } else {
19                s2.push(it);
20            }
21        }
22
23        return s1 == s2;
24    }
25};
26