// Last updated: 11/2/2026, 2:56:31 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        deque<int> dq;
5        vector<int> ans;
6        int n = nums.size();
7        for(int i = 0 ; i<n ; i++){
8            // piche se agar koi element chhota hai to usse hata do wo waise bhi nahi ho sakat ans curr element ki wajah se
9            while(!dq.empty() && nums[dq.back()] <=nums[i]) dq.pop_back();
10            // front se ans lena hai to jo bhi range se bahar hai yani window se bahr hai unhe hata denge
11            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
12            dq.push_back(i);
13            // and me tabhi daalemege jab window valid rhegi
14            if(i>=k-1)
15            ans.push_back(nums[dq.front()]);
16        }
17        return ans ;
18    }
19};