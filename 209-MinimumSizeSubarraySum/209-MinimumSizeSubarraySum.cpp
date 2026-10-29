// Last updated: 10/29/2026, 3:40:09 PM
1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int n = nums.size();
5        int l = 0;
6        int r = 0;
7        int ans = 1e9;
8        int sum = 0;
9        while (r < n) {
10            sum += nums[r];
11            while (sum >= target) {
12                ans = min(ans, r - l + 1);
13                sum -= nums[l++];
14            }
15            r++;
16        }
17        return ans == 1e9 ? 0 : ans;
18    }
19};