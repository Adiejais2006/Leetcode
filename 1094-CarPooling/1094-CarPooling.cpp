// Last updated: 11/1/2026, 12:15:51 AM
1class Solution {
2    static bool comp(const vector<int>& a, const vector<int>& b) {
3        return a[1] < b[1];
4    }
5
6public:
7    bool carPooling(vector<vector<int>>& trips, int capacity) {
8        priority_queue<pair<int, int>, vector<pair<int, int>>,
9                       greater<pair<int, int>>>
10            pq;
11
12        int cap = 0;
13        int n = trips.size();
14        sort(trips.begin(), trips.end(), comp);
15
16        for (int i = 0; i < n; i++) {
17            int passenger = trips[i][0];
18            int start = trips[i][1];
19            int end = trips[i][2];
20            while (!pq.empty() && pq.top().first <= start) {
21                cap -= pq.top().second;
22                pq.pop();
23            }
24            cap += passenger;
25            if (cap > capacity)
26                return false;
27            pq.push({end, passenger});
28        }
29        return true;
30    }
31};