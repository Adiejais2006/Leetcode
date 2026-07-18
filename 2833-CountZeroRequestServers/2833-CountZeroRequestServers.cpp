// Last updated: 7/18/2026, 2:00:07 PM
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        unordered_map<int, int> freq;

        int left = 0, right = 0;
        int active = 0;

        for (auto &[time, idx] : q) {
            while (right < logs.size() && logs[right][1] <= time) {
                if (++freq[logs[right][0]] == 1) active++;
                right++;
            }

            while (left < right && logs[left][1] < time - x) {
                if (--freq[logs[left][0]] == 0) active--;
                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};