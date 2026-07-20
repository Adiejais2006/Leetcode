// Last updated: 7/20/2026, 11:55:23 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int n = nums.size();
5        int low = 0;
6        int high = n - 1;
7        int ans = INT_MAX;
8        while (low <= high) {
9            int mid = (low + (high - low) / 2);
10            if (nums[low] <= nums[high]) {
11                ans = min(ans, nums[low]);
12                break;
13            }
14            // left sorted
15            ans = min(nums[mid], ans);
16            if (nums[mid] > nums[high]) {
17                low = mid + 1;
18            }
19            // right sorted
20            else {
21                high = mid - 1;
22            }
23        }
24        return ans;
25    }
26};