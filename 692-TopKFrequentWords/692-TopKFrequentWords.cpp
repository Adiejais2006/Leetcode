// Last updated: 7/18/2026, 2:03:45 PM
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for (auto &word : words) {
            mpp[word]++;
        }
        auto comp = [](const pair<int, string>& a,
                       const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second;   
            return a.first < b.first;         
        };
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            decltype(comp)
        > pq(comp);
        for (auto &it : mpp) {
            pq.push({it.second, it.first});
        }
        vector<string> ans;
        while (!pq.empty() && k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};