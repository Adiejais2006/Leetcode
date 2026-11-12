// Last updated: 11/12/2026, 5:09:08 PM
1class Solution {
2public:
3    int findMinArrowShots(vector<vector<int>>& points) {
4        sort(points.begin(), points.end());
5        int n = points.size();
6        int ans = 1;
7        int end = points[0][1];
8        for (int i = 1; i < n; i++) {
9            if (points[i][0] <= end) {
10                end = min(end, points[i][1]);
11            } else {
12                ans++;
13                end = points[i][1];
14            }
15        }
16        return ans;
17    }
18};