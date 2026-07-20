// Last updated: 7/21/2026, 12:38:15 AM
1class Solution { long long helper(int no, vector<int>& nums) {
2        int n = nums.size();
3        long long sum = 0;
4        for (int i = 0; i < n; i++) {
5            sum = sum + ((nums[i] + no - 1) / no);
6        }
7        return sum;
8    }
9public:
10    int minEatingSpeed(vector<int>& nums, int h) {
11         int n = nums.size();
12        int low = 1;
13        int high = INT_MIN;
14        for (int i = 0; i < n; i++) {
15            high = max(high, nums[i]);
16        }
17        int ans = INT_MAX;
18        while (low <= high) {
19            int mid = (low + high) / 2;
20
21            if (helper(mid, nums) > h) {
22                low = mid + 1;
23            } else {
24                ans = min(ans, mid);
25                high = mid - 1;
26            }
27        }
28        return ans;
29    }
30};