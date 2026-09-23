// Last updated: 9/23/2026, 3:10:11 PM
1class Solution {
2public:
3    int minCostConnectPoints(vector<vector<int>>& points) {
4        int n = points.size();
5        vector<int> vis(n, 0);
6        priority_queue<pair<int, int>, vector<pair<int, int>>,
7                       greater<pair<int, int>>>
8            pq;
9        pq.push({0, 0});
10        int sum = 0 ; 
11        while (!pq.empty()) {
12            auto [wt, node] = pq.top();
13            pq.pop();
14            if (vis[node])
15                continue;
16            vis[node] = 1;
17            sum += wt;
18            for (int i = 0; i < n; i++) {
19                if (!vis[i]) {
20                    int cost = abs(points[node][0] - points[i][0]) +
21                               abs(points[node][1] - points[i][1]);
22
23                    pq.push({cost, i});
24                }
25            }
26        }
27        return sum ;
28    }
29};