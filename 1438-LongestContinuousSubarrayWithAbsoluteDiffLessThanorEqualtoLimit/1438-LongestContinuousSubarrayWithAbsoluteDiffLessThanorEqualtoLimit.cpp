// Last updated: 9/5/2026, 5:47:05 PM
1class Solution {
2public:
3    int longestSubarray(vector<int>& nums, int limit) {
4        deque<int> maxdq;
5        deque<int> mindq;
6        int n = nums.size();
7        int l = 0;
8        int ans = 0;
9        for (int r = 0; r < n; r++) {
10            while (!maxdq.empty() && nums[maxdq.back()] <= nums[r]) {
11                maxdq.pop_back();
12            }
13            maxdq.push_back(r);
14            while (!mindq.empty() && nums[mindq.back()] >= nums[r]) {
15                mindq.pop_back();
16            }
17            mindq.push_back(r);
18            while (nums[maxdq.front()] - nums[mindq.front()] > limit) {
19                l++;
20                while (!maxdq.empty() && maxdq.front() < l)
21                    maxdq.pop_front();
22
23                while (!mindq.empty() && mindq.front() < l)
24                    mindq.pop_front();
25            }
26            ans = max(ans, r - l + 1);
27        }
28        return ans;
29    }
30};