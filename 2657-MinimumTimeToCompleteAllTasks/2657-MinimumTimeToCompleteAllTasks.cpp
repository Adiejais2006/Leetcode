// Last updated: 7/18/2026, 2:00:23 PM
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        vector<int> used(2001);

        for (auto &t : tasks) {
            int start = t[0];
            int end = t[1];
            int dur = t[2];

            for (int i = start; i <= end; i++) {
                dur -= used[i];
            }

            for (int i = end; i >= start && dur > 0; i--) {
                if (!used[i]) {
                    used[i] = 1;
                    dur--;
                }
            }
        }

        return accumulate(used.begin(), used.end(), 0);
    }
};