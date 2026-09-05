// Last updated: 9/5/2026, 3:45:27 PM
1class Solution {
2public:
3    string predictPartyVictory(string s) {
4        int n = s.size();
5        queue<int> r;
6        queue<int> d;
7        for (int i = 0; i < n; i++) {
8            if (s[i] == 'R')
9                r.push(i);
10            else
11                d.push(i);
12        }
13        int a = n;
14        while (!r.empty() && !d.empty()) {
15
16            while (!d.empty() && !r.empty() && r.front() < d.front()) {
17                r.pop();
18                d.pop();
19                r.push(a++);
20            }
21            while (!d.empty() && !r.empty() && d.front() < r.front()) {
22                r.pop();
23                d.pop();
24                d.push(a++);
25            }
26        }
27        if (!d.empty())
28            return "Dire";
29        else
30            return "Radiant";
31    }
32};