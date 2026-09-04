// Last updated: 9/4/2026, 3:37:10 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        deque<int> dq;
5        vector<int> ans;
6        int n = nums.size();
7        for (int i = 0; i < n; i++) {
8            while (!dq.empty() && dq.front() <= i - k)
9                dq.pop_front();
10            while (!dq.empty() && nums[dq.back()] <= nums[i])
11                dq.pop_back();
12            dq.push_back(i);
13            if (i >= k - 1)
14            ans.push_back(nums[dq.front()]);
15        }
16        return ans;
17    }
18};