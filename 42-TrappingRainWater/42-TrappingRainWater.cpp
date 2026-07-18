// Last updated: 7/18/2026, 4:37:45 PM
1class Solution {
2public:
3    int trap(vector<int>& nums) {
4        int n = nums.size();
5        int lmax = nums[0];
6        int rmax = nums[n - 1];
7        vector<int> lmaxx(n);
8        vector<int> rmaxx(n);
9        for (int i = 0; i < n; i++) {
10            lmax = max(nums[i], lmax);
11            rmax = max(nums[n - 1 - i], rmax);
12            lmaxx[i] = max(lmax, nums[i]);
13            rmaxx[n - i - 1] = max(rmax, nums[n - 1 - i]);
14        }
15        int ans = 0;
16        for (int i = 0; i < n; i++) {
17            ans += min(lmaxx[i], rmaxx[i]) - nums[i];
18        }
19        return ans;
20    }
21};