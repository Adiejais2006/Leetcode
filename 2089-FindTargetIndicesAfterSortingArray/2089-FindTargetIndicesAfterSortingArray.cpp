// Last updated: 8/5/2026, 5:03:13 PM
1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        sort(nums.begin(), nums.end());
5        int l = 0;
6        int h = nums.size() - 1;
7        int ind = -1;
8        while (l <= h) {
9            int mid = l + (h - l) / 2;
10            if (nums[mid] >= target) {
11                ind = mid;
12                h = mid - 1;
13            } else {
14                l = mid + 1;
15            }
16        }
17        vector<int> ans;
18        for (ind; ind < nums.size(); ind++) {
19            if (nums[ind] == target)
20                ans.push_back(ind);
21        }
22        return ans;
23    }
24};