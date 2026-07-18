// Last updated: 7/18/2026, 2:03:29 PM
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mpp;

        for (char ch : s)
            mpp[ch]++;

        priority_queue<pair<int, char>> pq;

        for (auto it : mpp)
            pq.push({it.second, it.first});

        string ans = "";

        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ans += it.second;
            it.first--;

            if (prev.first > 0)
                pq.push(prev);

            prev = it;
        }

        if (ans.size() != s.size())
            return "";

        return ans;
    }
};