// Last updated: 7/18/2026, 2:03:26 PM


class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz;

public:
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for (int x : nums) {
            add(x);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > sz) {
            pq.pop();
        }
        return pq.top();
    }
};