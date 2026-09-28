// Last updated: 9/28/2026, 3:51:21 PM
1class Solution {
2public:
3    int maxDepth(std::string s) {
4        int depth = 0;
5        int r = 0;
6        for (char c : s) {
7            if (c == ')') {
8                depth--;
9                continue;
10            }
11            if (c != '(') continue;
12            depth++;
13            if (depth > r) r = depth;
14        }
15        return r;
16    }
17};