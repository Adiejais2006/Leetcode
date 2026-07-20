// Last updated: 7/20/2026, 11:51:15 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n = nums.size();
5        int low = 0;
6        int high = n - 1;
7        int ans = INT_MAX;
8        while (low <= high) {
9            int mid = (low + (high - low) / 2);
10            // left sorted
11            ans = min(nums[mid], ans);
12            if (nums[mid] > nums[high]) {
13                low = mid + 1;
14            }
15            // right sorted
16            else {
17                high = mid - 1;
18            }
19        }
20        return ans;
21    }
22};