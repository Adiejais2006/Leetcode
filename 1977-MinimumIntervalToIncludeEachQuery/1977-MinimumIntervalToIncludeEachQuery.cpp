// Last updated: 7/18/2026, 2:01:23 PM
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        sort(intervals.begin(), intervals.end());

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans(queries.size(), -1);

        int j = 0;

        for (auto &[val, idx] : q) {
            while (j < intervals.size() && intervals[j][0] <= val) {
                int l = intervals[j][0];
                int r = intervals[j][1];

                pq.push({r - l + 1, r});
                j++;
            }

            while (!pq.empty() && pq.top().second < val) {
                pq.pop();
            }

            if (!pq.empty()) {
                ans[idx] = pq.top().first;
            }
        }

        return ans;
    }
};