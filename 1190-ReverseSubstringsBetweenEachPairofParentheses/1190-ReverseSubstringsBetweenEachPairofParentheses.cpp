// Last updated: 9/27/2026, 6:05:48 PM
1class Solution {
2public:
3    string reverseParentheses(auto& s) {
4        int n = s.size();
5        vector<int> link(n), stk;
6
7        for (int i = 0; i < n; i++) {
8            if (s[i] == '(')
9                stk.push_back(i);
10            else if (s[i] == ')') {
11                link[i] = stk.back();
12                link[link[i]] = i;
13                stk.pop_back();
14            }
15        }
16
17        string res;
18        for (int i = 0, dir = 1; i < n; i += dir) {
19            if (s[i] >= 'a')
20                res += s[i];
21            else {
22                i = link[i];
23                dir = -dir;
24            }
25        }
26
27        return res;
28    }
29};