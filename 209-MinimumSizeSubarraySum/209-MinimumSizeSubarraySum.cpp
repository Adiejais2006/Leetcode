// Last updated: 7/18/2026, 7:30:04 PM
1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int len = INT_MAX;
5        int l = 0;
6        int r = 0;
7        int n = nums.size();
8        int sum = 0;
9        while (r < n) {
10            sum += nums[r];
11            while (sum >= target) {
12                len = min(len, r - l + 1);
13                sum -= nums[l];
14                l++;
15            }
16            r++;
17        }
18
19        if (len == INT_MAX)
20            return 0;
21        return len;
22    }
23};