// Last updated: 11/20/2026, 8:06:23 PM
1class Solution {
2public:
3    int maxSelectedElements(vector<int>& nums) {
4        ranges::sort(nums);
5        int best = 1, keep = 1, bump = 1, last = -10;
6        for (int x : nums) {
7            switch (x - last) {
8                case 0: bump = keep + 1; break;  // x repeat: bump it on top of keep
9                case 1: ++keep, ++bump; break;  // x extends keep, x + 1 extends bump
10                case 2: keep = bump + 1, bump = 1; break;  // x extends bump, x + 1 starts over
11                default: keep = bump = 1;
12            }
13            best = max({best, keep, bump}), last = x;
14        }
15        return best;
16    }
17};