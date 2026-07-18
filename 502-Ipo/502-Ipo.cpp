// Last updated: 7/18/2026, 2:04:16 PM
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<vector<int>> vec;
        int i = 0;
        for (auto it : capital) {
            vec.push_back({it, i});
            i++;
        }
        int n = vec.size();
        sort(vec.begin(), vec.end());
        priority_queue<int> pq; // max heap
        i = 0;
        while (k > 0) {
            while (i < n && vec[i][0] <= w) {
                pq.push(profits[vec[i][1]]); i++;
            }
            if (pq.empty())
                break;
            w = w + pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};