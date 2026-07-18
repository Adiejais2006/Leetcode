// Last updated: 7/18/2026, 2:04:52 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (auto it : nums)
            mpp[it]++;
        priority_queue<pair<int, int>> pq;
        // freq and number

        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }
        vector<int> ans;

        while (!pq.empty() && k > 0) {

            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};