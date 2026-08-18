// Last updated: 8/18/2026, 12:46:00 PM
1class Solution {
2public:
3    int largestInteger(vector<int>& nums, int k) {
4        int n = nums.size();
5        unordered_map<int, int> mpp;
6        for (int x : nums)
7            mpp[x]++;
8        if (k == n)
9            return *max_element(nums.begin(), nums.end());
10        if (k == 1) {
11            int ans = -1;
12            for (int x : nums) {
13                if (mpp[x] == 1)
14                    ans = max(ans, x);
15            }
16            return ans;
17        }
18        int ans = -1;
19        if (mpp[nums[0]] == 1)
20            ans = max(ans, nums[0]);
21
22        if (mpp[nums[n - 1]] == 1)
23            ans = max(ans, nums[n - 1]);
24
25        return ans;
26    }
27};