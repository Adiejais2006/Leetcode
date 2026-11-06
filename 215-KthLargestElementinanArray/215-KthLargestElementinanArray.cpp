// Last updated: 11/6/2026, 6:25:29 PM
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4        int n = nums.size();
5        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),
6                                                          nums.begin() + k);
7        int i = k;
8
9        for (i; i < n; i++) {
10            if (nums[i] > pq.top()) {
11                pq.pop();
12                pq.push(nums[i]);
13            }
14        }
15        return pq.top();
16    }
17};