// Last updated: 11/2/2026, 2:34:59 PM
1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        int n = nums.size();
5        priority_queue<pair<int, int>>
6            pq;
7        int l = 0;
8        int r = 0;
9        while (r < k) {
10            pq.push({nums[r], r});
11            r++;
12        }
13        vector<int> ans;
14        ans.push_back(pq.top().first);
15        l = 1;
16        while (!pq.empty() && r < n && l < n) {
17            while (!pq.empty() && pq.top().second < l) {
18                pq.pop();
19            }
20            pq.push({nums[r], r});
21            ans.push_back(pq.top().first);
22            l++;
23            r++;
24        }
25        return ans;
26    }
27};