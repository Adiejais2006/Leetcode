// Last updated: 11/2/2026, 2:54:31 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        deque<int> dq;
5        vector<int> ans;
6        int n = nums.size();
7        for(int i = 0 ; i<n ; i++){
8            while(!dq.empty() && nums[dq.back()] <=nums[i]) dq.pop_back();
9            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
10            dq.push_back(i);
11            if(i>=k-1)
12            ans.push_back(nums[dq.front()]);
13        }
14        return ans ;
15    }
16};