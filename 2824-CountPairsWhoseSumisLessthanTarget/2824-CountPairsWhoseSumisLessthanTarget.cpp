// Last updated: 11/4/2026, 6:28:46 PM
1class Solution {
2public:
3    int countPairs(vector<int>& nums, int target) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size();
6        int l = 0;
7        int r = n - 1;
8        int ans = 0;
9        while (l < r) {
10            if (nums[l] + nums[r] < target) {
11                ans += r - l;
12                l++;
13            } else
14                r--;
15        }
16        return ans;
17    }
18};