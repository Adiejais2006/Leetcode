// Last updated: 10/22/2026, 10:05:27 PM
1class Solution {
2public:
3    int mincostTickets(vector<int>& days, vector<int>& costs) {
4        int n = days.size();
5        vector<int> dp(n + 1);
6
7        for (int i = n - 1; i >= 0; i--) {
8            int j = i;
9
10            while (j < n && days[j] < days[i] + 1)
11                j++;
12            int one = costs[0] + dp[j];
13
14            j = i;
15            while (j < n && days[j] < days[i] + 7)
16                j++;
17            int seven = costs[1] + dp[j];
18
19            j = i;
20            while (j < n && days[j] < days[i] + 30)
21                j++;
22            int thirty = costs[2] + dp[j];
23
24            dp[i] = min({one, seven, thirty});
25        }
26
27        return dp[0];
28    }
29};