// Last updated: 7/20/2026, 10:41:34 PM
1class Solution {
2    int upperIndex(vector<int>& nums, int target) {
3        int n = nums.size();
4        int low = 0;
5        int high = n - 1;
6        int ans = -1;
7        while (low <= high) {
8            int mid = (low + high) / 2;
9            if (nums[mid] == target) {
10                ans = mid;
11                low = mid + 1;
12            } else if (nums[mid] > target) {
13                high = mid - 1;
14            } else
15                low = mid + 1;
16        }
17        return ans;
18    }
19    int lowerIndex(vector<int>& nums, int target) {
20        int n = nums.size();
21        int low = 0;
22        int high = n - 1;
23        int ans = -1;
24        while (low <= high) {
25            int mid = (low + high) / 2;
26            if (nums[mid] == target) {
27                ans = mid;
28                high = mid - 1;
29            } else if (nums[mid] > target) {
30                high = mid - 1;
31            } else
32                low = mid + 1;
33        }
34        return ans;
35    }
36
37public:
38    vector<int> searchRange(vector<int>& nums, int target) {
39        int start = lowerIndex(nums, target);
40        if (start == -1)
41            return {-1, -1};
42        int end = upperIndex(nums, target);
43        return {start, end};
44    }
45};