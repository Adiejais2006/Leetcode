// Last updated: 9/22/2026, 9:31:43 PM
1class Solution {
2public:
3    int minimumCost(vector<int>& start, vector<int>& target,
4                    vector<vector<int>>& specialRoads) {
5        int startX = start[0], startY = start[1];
6        int targetX = target[0], targetY = target[1];
7        if (startX == targetX && startY == targetY)
8            return 0;
9        map<pair<int, int>, int> cost;
10        cost[{startX, startY}] = 0;
11        cost[{targetX, targetY}] = 1e9 + 8621;
12        priority_queue<pair<int, pair<int, int>>,
13                       vector<pair<int, pair<int, int>>>,
14                       greater<pair<int, pair<int, int>>>>
15            pq;
16        pair<int, pair<int, int>> tuple = {0, {startX, startY}};
17        pq.push(tuple);
18        while (!pq.empty()) {
19            tuple = pq.top();
20            pq.pop();
21            int currX = tuple.second.first;
22            int currY = tuple.second.second;
23            int currCost = tuple.first;
24            if (currX == targetX && currY == targetY)
25                return currCost;
26            if (cost[{targetX, targetY}] >
27                currCost + abs(currX - targetX) + abs(currY - targetY)) {
28                cost[{targetX, targetY}] =
29                    currCost + abs(currX - targetX) + abs(currY - targetY);
30                pq.push({cost[{targetX, targetY}], {targetX, targetY}});
31            }
32            for (vector<int>& road : specialRoads) {
33                int toReachCost = currCost + abs(currX - road[0]) +
34                                  abs(currY - road[1]) + road[4];
35                if (cost.find({road[2], road[3]}) == cost.end() ||
36                    cost[{road[2], road[3]}] > toReachCost) {
37                    cost[{road[2], road[3]}] = toReachCost;
38                    pq.push({toReachCost, {road[2], road[3]}});
39                }
40            }
41        }
42        return -1;
43    }
44};