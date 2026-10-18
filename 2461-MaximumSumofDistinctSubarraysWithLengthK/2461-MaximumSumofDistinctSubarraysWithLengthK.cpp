// Last updated: 10/18/2026, 10:08:36 PM
1class Solution {
2public:
3    long long maximumSubarraySum(vector<int>& nums, int k) {
4        long long ans = 0;
5        int n = nums.size();
6        int l = 0;
7        int r = 0;
8        unordered_map<int, int> mpp;
9        long long sum = 0;
10        while (r < k) {
11            sum += nums[r];
12            mpp[nums[r]]++;
13            r++;
14        }
15
16        if (mpp.size() == k) {
17            ans = max(ans, sum);
18        }
19        while (r < n) {
20            sum -= nums[l];
21            sum += nums[r];
22            mpp[nums[l]]--;
23            if (mpp[nums[l]] == 0)
24                mpp.erase(nums[l]);
25            mpp[nums[r]]++;
26            if (mpp.size() == k) {
27                ans = max(ans, sum);
28            }
29            r++;
30            l++;
31        }
32        return ans;
33    }
34};