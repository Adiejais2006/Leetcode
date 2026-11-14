// Last updated: 11/14/2026, 2:37:47 PM
1class Solution {
2public:
3    int minimumSumSubarray(vector<int>& nums, int l, int r) {
4        int n = nums.size();
5        vector<int> prefix(n + 1, 0);
6        for (int i = 0; i < n; i++)
7            prefix[i + 1] = prefix[i] + nums[i];
8        int best = INT_MAX;
9        for (int len = l; len <= r; len++) {
10            for (int i = 0; i + len <= n; i++) {
11                int sum = prefix[i + len] - prefix[i];
12                if (sum > 0 && sum < best) best = sum;
13            }
14        }
15
16        return best == INT_MAX ? -1 : best;
17    }
18};