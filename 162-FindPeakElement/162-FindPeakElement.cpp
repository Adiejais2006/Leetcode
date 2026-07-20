// Last updated: 7/21/2026, 12:11:15 AM
1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int low = 0;
5        int high = nums.size() - 1;
6        while (low < high) {
7            int mid = low + (high - low) / 2;
8            if (nums[mid] < nums[mid + 1]) {
9                low = mid + 1;
10            } else {
11                high = mid;
12            }
13        }
14
15        return low;
16    }
17};