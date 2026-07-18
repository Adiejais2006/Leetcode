// Last updated: 7/18/2026, 2:00:41 PM
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<long long> cnt(n, 0);

        priority_queue<int, vector<int>, greater<int>> available;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        for (auto& m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();

                cnt[room]++;
                busy.push({end, room});
            } else {
                auto [freeTime, room] = busy.top();
                busy.pop();

                cnt[room]++;
                busy.push({freeTime + duration, room});
            }
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (cnt[i] > cnt[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};