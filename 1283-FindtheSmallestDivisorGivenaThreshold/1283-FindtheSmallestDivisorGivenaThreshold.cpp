// Last updated: 7/21/2026, 3:13:33 PM
1class Solution {
2    int helper(vector<int>& nums, int threshold, int divisor) {
3        int cnt = 0;
4        for (auto it : nums) {
5            cnt += (it + divisor - 1) / divisor;
6        }
7        return cnt;
8    }
9
10public:
11    int smallestDivisor(vector<int>& nums, int threshold) {
12        int low = 1;
13        int high = INT_MIN;
14        for (auto it : nums) {
15            high = max(high, it);
16        }
17
18        while (low <= high) {
19            int mid = low + (high - low) / 2;
20            int hold = helper(nums, threshold, mid);
21            if (hold <= threshold) {
22                high = mid - 1;
23            } else {
24                low = mid + 1;
25            }
26        }
27        return low;
28    }
29};