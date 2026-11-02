// Last updated: 11/2/2026, 3:38:25 PM
1class Solution {
2public:
3    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
4        int n = intervals.size();
5        if (n == 0)
6            return 0;
7        sort(intervals.begin(), intervals.end());
8        int ans = 0;
9        int end = intervals[0][1];
10        for (int i = 1; i < n; i++) {
11            if (intervals[i][0] < end) {
12                ans++;
13                end = min(end, intervals[i][1]);
14            } else
15                end = intervals[i][1];
16        }
17
18        return ans;
19    }
20};