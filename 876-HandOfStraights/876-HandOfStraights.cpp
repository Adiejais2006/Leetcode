// Last updated: 7/18/2026, 2:03:14 PM
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        unordered_map<int, int> mpp;
        for (auto it : hand) {
            mpp[it]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        for (auto it : mpp) {
            pq.push({it.first, it.second}); // number, frequency
        }
        queue<pair<int, int>> q;
        while (!pq.empty()) {
            int cnt = 0;
            int prev = -1;
            while (cnt < groupSize) {
                if (pq.empty())
                    return false;
                auto it = pq.top();
                pq.pop();
                int no = it.first;
                int freq = it.second;
                freq--;
                if (prev != -1 && prev + 1 != no)
                    return false;
                prev = no;
                if (freq > 0)
                    q.push({no, freq});
                cnt++;
            }
            while (!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
        return true;
    }
};