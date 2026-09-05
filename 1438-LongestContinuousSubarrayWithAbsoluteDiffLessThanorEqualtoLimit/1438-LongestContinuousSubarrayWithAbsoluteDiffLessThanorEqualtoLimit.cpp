// Last updated: 9/5/2026, 6:17:42 PM
1class Solution {
2public:
3    int longestSubarray(vector<int>& nums, int limit) {
4        int l = 0;
5        int r = 0;
6        int n = nums.size();
7        int ans = 0;
8        priority_queue<pair<int, int>> maxheap;
9        priority_queue<pair<int, int>, vector<pair<int, int>>,
10                       greater<pair<int, int>>>
11            minheap;
12        while (r < n) {
13            maxheap.push({nums[r], r});
14            minheap.push({nums[r], r});
15            while (maxheap.top().first - minheap.top().first > limit) {
16                l = min(maxheap.top().second, minheap.top().second) + 1 ;
17                while (maxheap.top().second < l)
18                    maxheap.pop();
19                while (minheap.top().second < l)
20                    minheap.pop();
21            }
22            ans = max(ans, r - l + 1);
23            r++;
24        }
25        return ans;
26    }
27};