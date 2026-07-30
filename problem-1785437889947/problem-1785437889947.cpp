// Last updated: 7/31/2026, 12:28:09 AM
1class Solution {
2public:
3    int minimumPushes(string A) {
4        auto q = A.size() >> 3, r = A.size() & 7;
5        return ((q << 2) + r) * (q + 1);
6    }
7};