// Last updated: 11/1/2026, 9:36:28 PM
1class KthLargest {
2    priority_queue<int, vector<int>, greater<int>> pq;
3    int sz;
4public:
5    KthLargest(int k, vector<int>& nums) {
6        int n = nums.size();
7        sz = k;
8        int i = 0;
9        while (i < sz && i < n) {
10            pq.push(nums[i++]);
11        }
12        while (i < n) {
13            if (pq.top() < nums[i]) {
14                pq.pop();
15                pq.push(nums[i]);
16            }
17            i++;
18        }
19    }
20    int add(int val) {
21        if (pq.size() < sz) {
22            pq.push(val);
23        } 
24        else if (val > pq.top()) {
25            pq.pop();
26            pq.push(val);
27        }
28        return pq.top();
29    }
30};
31