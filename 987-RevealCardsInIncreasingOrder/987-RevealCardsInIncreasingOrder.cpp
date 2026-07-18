// Last updated: 7/18/2026, 2:02:55 PM
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        priority_queue<int> pq;
        for (auto it : deck) {
            pq.push(it);
        }
        deque<int> dq;
        dq.push_front(pq.top());
        pq.pop();

        if (!pq.empty()) {
            dq.push_front(pq.top());
            pq.pop();
        }

        while(!pq.empty()){
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(pq.top());
            pq.pop();
        }

        vector<int> ans;    
        while(!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans ;
    }
};