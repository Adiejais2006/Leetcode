// Last updated: 7/21/2026, 12:07:35 AM
1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int n = nums.size();
5        int low = 0;
6        int high = n - 1;
7        while (low <= high) {
8            int mid = low + (high - low) / 2;
9            if (mid < n-1 && nums[mid] < nums[mid + 1]) {
10                low = mid + 1;
11            } else
12                high = mid - 1;
13        }
14        return low;
15    }
16};