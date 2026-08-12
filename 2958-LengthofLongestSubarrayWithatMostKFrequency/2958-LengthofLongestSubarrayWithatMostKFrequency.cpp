// Last updated: 8/12/2026, 12:29:10 PM
1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        int n = nums.size();
5        int l = 0;
6        int r = 0;
7        unordered_map<int, int> mpp;
8        int ans = 0;
9        while (r < n) {
10            mpp[nums[r]]++;
11
12            while (mpp[nums[r]] > k) {
13                mpp[nums[l]]--;
14                if (mpp[nums[l]] == 0) {
15                    mpp.erase(nums[l]);
16                }
17                l++;
18            }
19            ans = max(ans, r - l + 1);
20            r++;
21        }
22        return ans;
23    }
24};