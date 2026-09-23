// Last updated: 9/23/2026, 3:03:43 PM
1class Solution {
2public:
3    void dfs(int current, int distance, const vector<int>& edges, vector<int>& distances) {
4        while (current != -1 && distances[current] == -1) {
5            distances[current] = distance++;
6            current = edges[current];
7        }
8    }
9
10    int closestMeetingNode(vector<int>& edges, int start1, int start2) {
11        int res = -1, Min_Of_Max = INT_MAX, n = edges.size();
12        vector<int> dist1(n, -1), dist2(n, -1);
13        dfs(start1, 0, edges, dist1);
14        dfs(start2, 0, edges, dist2);
15
16        for (int i = 0; i < n; i++) {
17            if (dist1[i] >= 0 && dist2[i] >= 0) {
18                int maxDist = max(dist1[i], dist2[i]);
19                if (maxDist < Min_Of_Max) {
20                    Min_Of_Max = maxDist;
21                    res = i;
22                }
23            }
24        }
25        return res;
26    }
27};