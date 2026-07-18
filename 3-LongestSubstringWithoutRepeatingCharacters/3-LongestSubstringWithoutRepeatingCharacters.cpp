// Last updated: 7/18/2026, 10:21:00 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string nums) {
4        int n = nums.size();
5        int l = 0;
6        int r = 0;
7        int ans = 0;
8        unordered_map<int, int> mpp;
9        while (r < n) {
10            mpp[nums[r]]++;
11            while (mpp[nums[r]] > 1) {
12                mpp[nums[l]]--;
13                l++;
14            }
15            ans = max(ans, r - l + 1);
16            r++;
17        }
18        return ans;
19    }
20};