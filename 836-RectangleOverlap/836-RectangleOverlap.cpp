// Last updated: 9/14/2026, 1:14:54 PM
1class Solution {
2public:
3    bool isRectangleOverlap(auto& r1, auto& r2) {
4        return r1[0] < r2[2] && r2[0] < r1[2] &&
5               r1[1] < r2[3] && r2[1] < r1[3];
6    }
7};