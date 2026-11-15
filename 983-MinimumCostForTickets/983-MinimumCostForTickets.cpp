// Last updated: 11/15/2026, 4:03:42 PM
1class Solution {
2public:
3    int mincostTickets(vector<int>& days, vector<int>& costs) {
4        int n = days.size();
5        vector<int> dp(n +1);
6        for (int i = n - 1; i >= 0; i--) {
7            int j = i;
8            while (j < days.size() && days[j] < days[i] + 1) {
9                j++;    
10            }
11            int one = costs[0] + dp[j];
12            j = i;
13            while (j < days.size() && days[j] < days[i] + 7) {
14                j++;
15            }
16            int seven = costs[1] + dp[j];
17            j = i;
18            while (j < days.size() && days[j] < days[i] + 30) {
19                j++;
20            }
21            int thirty = costs[2] + dp[j];
22            dp[i] = min(one, min(seven, thirty));
23        }
24        return dp[0];
25    }
26};