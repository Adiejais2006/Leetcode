// Last updated: 11/3/2026, 11:43:05 PM
1class Solution {
2public:
3    vector<vector<int>> insert(vector<vector<int>>& intervals,
4                               vector<int>& newInterval) {
5        vector<vector<int>> ans;
6        int n = intervals.size();
7        if (n == 0)
8            return {newInterval};
9        int i = 0;
10        while (i < n && intervals[i][1] < newInterval[0]) {
11            ans.push_back(intervals[i]);
12            i++;
13        }
14        int start = newInterval[0];
15        int end = newInterval[1];
16        while (i < n && intervals[i][0] <= end) {
17            start = min(start, intervals[i][0]);
18            end = max(end, intervals[i][1]);
19            i++;
20        }
21        ans.push_back({start, end});
22        while (i < n) {
23            ans.push_back(intervals[i]);
24            i++;
25        }
26        return ans;
27    }
28};