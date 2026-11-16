// Last updated: 11/16/2026, 5:05:44 PM
1class Solution {
2    int func(vector<int>& nums, int k) {
3        int l = 0;
4        int r = 0;
5        int n = nums.size();
6        int cnt = 0;
7        int ans = 0;
8        while (r < n) {
9            if (nums[r] % 2 == 1)
10                cnt++;
11            while (cnt > k) {
12                if (nums[l++] % 2 == 1)
13                    cnt--;
14            }
15            ans += r - l + 1;
16            r++;
17        }
18        return ans;
19    }
20
21public:
22    int numberOfSubarrays(vector<int>& nums, int k) {
23        return func(nums, k) - func(nums, k - 1);
24    }
25};