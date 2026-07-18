// Last updated: 7/18/2026, 2:03:56 PM
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> pq; // freq, char
        queue<vector<int>> q;
        unordered_map<char, int> mpp;
        for (auto it : tasks) {
            mpp[it]++;
        }
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }
        int time = 0;
      
        while (!pq.empty() || !q.empty()) {
            if (!q.empty()) {
                auto i = q.front();
                if (i[0] <= time) {
                    pq.push({i[1], i[2]});
                    q.pop();
                }
            }
            if (!pq.empty()) {
                auto it = pq.top();
                pq.pop();
                it.first--;
               
                vector<int> temp(3); // time, freq, char
                if (it.first > 0) {
                  temp[0] = time + n + 1;
                    temp[1] = it.first;
                    temp[2] = it.second;
                    q.push(temp);
                }
            }
            time++;
        }
        return time;
    }
};