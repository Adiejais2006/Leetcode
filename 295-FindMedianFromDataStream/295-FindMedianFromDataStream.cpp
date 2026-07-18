// Last updated: 7/18/2026, 2:05:03 PM


class MedianFinder {
private:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        l.push(num);
        r.push(l.top());
        l.pop();
        
        if (l.size() < r.size()) {
            l.push(r.top());
            r.pop();
        }
    }
    
    double findMedian() {
        if (l.size() > r.size()) {
            return l.top();
        }
        return (l.top() + r.top()) / 2.0;
    }
};