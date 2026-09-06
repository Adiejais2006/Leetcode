// Last updated: 9/6/2026, 2:04:32 PM
1class Solution {
2
3public:
4    int maxResult(vector<int>& nums, int k) {
5        int n = nums.size();
6        deque<int> dq;
7        vector<int> dp(n + 1, INT_MIN);
8        dq.push_back(n - 1);
9        dp[n - 1] = nums[n - 1];
10        for (int i = n - 2; i >= 0; i--) {
11            while (!dq.empty() && dq.front() > i + k)
12                dq.pop_front();
13            dp[i] = nums[i] + dp[dq.front()];
14            while (!dq.empty() && dp[dq.back()] <= dp[i])
15                dq.pop_back();
16            dq.push_back(i);
17        }
18        return dp[0];
19    }
20};