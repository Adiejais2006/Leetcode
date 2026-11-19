// Last updated: 11/19/2026, 3:32:45 PM
1class Solution {
2public:
3    int minimizeSum(vector<int>& nums) {
4        int mn1 = INT_MAX, mn2 = INT_MAX, mn3 = INT_MAX;
5        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
6
7        for (int x : nums) {
8            if (x < mn1) {
9                mn3 = mn2;
10                mn2 = mn1;
11                mn1 = x;
12            } else if (x < mn2) {
13                mn3 = mn2;
14                mn2 = x;
15            } else if (x < mn3) {
16                mn3 = x;
17            }
18
19            if (x > mx1) {
20                mx3 = mx2;
21                mx2 = mx1;
22                mx1 = x;
23            } else if (x > mx2) {
24                mx3 = mx2;
25                mx2 = x;
26            } else if (x > mx3) {
27                mx3 = x;
28            }
29        }
30
31        return min({mx1 - mn3, mx2 - mn2, mx3 - mn1});
32    }
33};