// Last updated: 9/6/2026, 12:54:42 AM
1class Solution {
2public:
3    int longestSubarray(vector<int>& nums, int limit) {
4        int l = 0;
5        int r = 0;
6        int n = nums.size();
7        priority_queue<pair<int, int>, vector<pair<int, int>>,
8                       greater<pair<int, int>>>
9            minheap;
10        priority_queue<pair<int, int>> maxheap;
11        int ans = 0;
12        while (r < n) {
13            maxheap.push({nums[r], r});
14            minheap.push({nums[r], r});
15            while (maxheap.top().first - minheap.top().first > limit) {
16                l++;
17                while (!maxheap.empty() && maxheap.top().second < l)
18                    maxheap.pop();
19                while (!minheap.empty() && minheap.top().second < l)
20                    minheap.pop();
21            }
22            ans = max(ans, r - l + 1);
23            r++;
24        }
25        return ans;
26    }
27};