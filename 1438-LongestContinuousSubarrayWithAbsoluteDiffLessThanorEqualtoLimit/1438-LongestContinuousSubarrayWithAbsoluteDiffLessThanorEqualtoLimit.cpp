// Last updated: 9/6/2026, 1:15:44 AM
1class Solution {
2public:
3    int longestSubarray(vector<int>& nums, int limit) {
4        int n = nums.size();
5        int l = 0;
6        int r = 0;
7        deque<int> maxd;
8        deque<int> mind;
9        int ans = 0;
10        while (r < n) {
11            while (!maxd.empty() && nums[maxd.back()] <= nums[r])
12                maxd.pop_back();
13            maxd.push_back(r);
14            while (!mind.empty() && nums[mind.back()] >= nums[r])
15                mind.pop_back();
16            mind.push_back(r);
17            while (nums[maxd.front()] - nums[mind.front()] > limit) {
18                l++;
19                while (!maxd.empty() && maxd.front() < l)
20                    maxd.pop_front();
21                while (!mind.empty() && mind.front() < l)
22                    mind.pop_front();
23            }
24            ans = max(r - l + 1, ans);
25            r++;
26        }
27        return ans;
28    }
29};