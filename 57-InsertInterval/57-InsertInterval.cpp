// Last updated: 11/3/2026, 11:38:06 PM
1class Solution {
2public:
3    vector<vector<int>> insert(vector<vector<int>>& intervals,
4                               vector<int>& newInterval) {
5        vector<vector<int>> ans;
6        int n = intervals.size();
7        if(n==0)return {newInterval};
8        int i = 0;
9        while (i < n) {
10            if (intervals[i][1] >= newInterval[0]) {
11                break;
12            }
13            ans.push_back(intervals[i]);
14            i++;
15        }
16        int start = intervals[i][0];
17        int end = newInterval[1];
18        while (i < n && intervals[i][0] <= end) {
19            end = max(end, intervals[i][1]);
20            i++;
21        }
22        ans.push_back({start, end});
23        while (i < n) {
24            ans.push_back(intervals[i]);
25            i++;
26        }
27        return ans;
28    }
29};