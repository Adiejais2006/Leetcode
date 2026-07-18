// Last updated: 7/18/2026, 2:02:29 PM
class Solution {
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        int cap = 0;
        int n = trips.size();
        sort(trips.begin(), trips.end(), comp);

        for (int i = 0; i < n; i++) {
            int passenger = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
            while (!pq.empty() && pq.top().first <= start) {
                cap -= pq.top().second;
                pq.pop();
            }
            cap += passenger;
            if (cap > capacity)
                return false;
            pq.push({end, passenger});
        }
        return true;
    }
};