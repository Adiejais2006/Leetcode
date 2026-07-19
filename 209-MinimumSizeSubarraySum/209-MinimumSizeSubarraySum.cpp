// Last updated: 7/20/2026, 12:18:13 AM
1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int n = nums.size();
5        int l = 0;
6        int r = 0;
7        int len = INT_MAX;
8        int sum = 0;
9        while (r < n) {
10            sum += nums[r];
11            while (sum >= target) {
12                len = min(len, r - l + 1);
13                sum -= nums[l++];
14            }
15
16            r++;
17        }
18        if (len == INT_MAX)
19            return 0;
20        return len;
21    }
22};