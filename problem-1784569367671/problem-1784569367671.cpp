// Last updated: 7/20/2026, 11:12:47 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int n = nums.size();
5        int l = 0;
6        int h = n - 1;
7        while (l <= h) {
8            int mid = l + (h - l) / 2;
9            int el = nums[mid];
10            // left half sorted
11            if (nums[mid] == target)
12                return mid;
13            if (el > nums[h]) {
14
15                if (nums[l] <= target && target < el) {
16                    h = mid - 1;
17                } else
18                    l = mid + 1;
19            }
20            // right half sorted
21            else {
22
23                if (nums[mid] < target && target <= nums[h]) {
24                    l = mid + 1;
25                } else {
26                    h = mid - 1;
27                }
28            }
29        }
30        return -1;
31    }
32};