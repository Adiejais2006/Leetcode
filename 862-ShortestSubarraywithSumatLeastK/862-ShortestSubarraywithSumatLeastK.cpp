// Last updated: 9/4/2026, 11:21:00 PM
1class Solution {
2public:
3    int shortestSubarray(vector<int>& nums, int k) {
4        int n = nums.size();
5        deque<int> dq;
6        vector<int> prefix(n + 1, 0);
7        for (int i = 0; i < n; i++) {
8            prefix[i + 1] = prefix[i] + nums[i];
9        }
10        int ans = n + 1;
11
12        for (int i = 0; i <= n; i++) {
13
14            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
15                ans = min(ans, i - dq.front());
16                dq.pop_front();
17            }
18            while (!dq.empty() && prefix[dq.back()] >= prefix[i]) {
19                dq.pop_back();
20            }
21            dq.push_back(i);
22        }
23        return ans == n + 1 ? -1 : ans;
24    }
25};