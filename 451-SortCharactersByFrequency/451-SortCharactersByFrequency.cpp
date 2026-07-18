// Last updated: 7/18/2026, 2:04:32 PM
class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char, int> mpp;
        for (auto it : s) {
            mpp[it]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            char inserted = it.second;
            int times = it.first;
            while (times > 0) {
                ans += inserted;
                times--;
            }

        }
        return ans;
    }
};