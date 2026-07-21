// Last updated: 7/21/2026, 8:07:19 PM
1class Solution {
2
3    int helper(vector<int>& nums, int k, int mid) {
4        int l = 0;
5        int r = 0;
6        int n = nums.size();
7        int cnt = 0;
8        while (r < n) {
9            while (nums[r] - nums[l] > mid) {
10                l++;
11            }
12            cnt += r - l;
13            r++;
14        }
15        return cnt;
16    }
17
18public:
19    int smallestDistancePair(vector<int>& nums, int k) {
20        sort(nums.begin(), nums.end());
21        int n = nums.size();
22        int low = 0;
23        int high = nums[n - 1] - nums[0];
24
25        while (low <= high) {
26            int mid = low + (high - low) / 2;
27            int val = helper(nums, k, mid);
28            if (val >= k) {
29                high = mid - 1;
30            } else
31                low = mid + 1;
32        }
33        return low;
34    }
35};