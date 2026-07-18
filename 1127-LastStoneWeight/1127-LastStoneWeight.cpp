// Last updated: 7/18/2026, 2:02:36 PM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
            pq.push(stones[i]);
        while (pq.size() > 1) {
            auto max1 = pq.top();
            pq.pop();
            auto max2 = pq.top();
            pq.pop();

            if (max1 == max2)
                continue;
            else
                pq.push(max1 - max2);
        }
        return pq.empty() ? 0 : pq.top();
    }
};