// Last updated: 9/23/2026, 3:09:15 PM
1class Solution {
2public:
3    vector<int> getDist(vector<int>& edges, int start) {
4        int n = edges.size();
5        vector<int> dist(n, -1);
6        int curr = start;
7        int d = 0;
8        while (curr != -1 && dist[curr] == -1) {
9            dist[curr] = d++;
10            curr = edges[curr];
11        }
12        return dist;
13    }
14    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
15        int n = edges.size();
16        vector<int> dist1 = getDist(edges, node1);
17        vector<int> dist2 = getDist(edges, node2);
18        int ans = -1;
19        int minDist = INT_MAX;
20        for (int i = 0; i < n; i++) {
21            if (dist1[i] == -1 || dist2[i] == -1)
22                continue;
23            int currDist = max(dist1[i], dist2[i]);
24            if (currDist < minDist) {
25                minDist = currDist;
26                ans = i;
27            }
28        }
29        return ans;
30    }
31};