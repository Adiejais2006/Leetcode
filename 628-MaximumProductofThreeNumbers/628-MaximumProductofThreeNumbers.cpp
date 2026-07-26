// Last updated: 7/27/2026, 12:32:31 AM
1class Solution {
2public:
3    int maximumProduct(vector<int>& A) {
4        int a = -1001, b = a, c = b;
5        int x = 1001, y = x;
6
7        for (auto& n : A) {
8            int pa = a, pb = b, px = x;
9
10            a = max(a, n);
11            b = max(b, min(pa, n));
12            c = max(c, min(pb, n));
13
14            x = min(x, n);
15            y = min(y, max(px, n));
16        }
17
18        return max(a * b * c, a * x * y);
19    }
20};