// Last updated: 7/21/2026, 2:39:57 PM
1class Solution {
2    int helper(vector<int>& nums, int k, int maxsum) {
3        int sum = 0;
4        int cnt = 1;
5        for (auto it : nums) {
6            sum += it;
7            if (sum > maxsum) {
8                sum = it;
9                cnt++;
10            }
11        }
12        return cnt;
13    }
14
15public:
16    int splitArray(vector<int>& nums, int k) {
17        int maxu = INT_MIN;
18        int sum = 0;
19        for (auto it : nums) {
20            maxu = max(maxu, it);
21            sum += it;
22        }
23        int low = maxu;
24        int high = sum;
25
26        while (low <= high) {
27            int mid = low + (high - low) / 2;
28
29            if (helper(nums, k, mid) > k) {
30                low = mid + 1;
31            } else
32                high = mid - 1;
33        }
34        return low;
35    }
36};