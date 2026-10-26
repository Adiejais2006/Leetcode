// Last updated: 10/26/2026, 2:23:08 PM
1class Solution {
2public:
3    long long countSubarrays(vector<int>& nums, long long k) {
4        long long n = nums.size();
5        long long ans = 0;
6        long long l = 0;
7        long long r = 0;
8        long long sum = 0;
9        while (r < n) {
10            sum += nums[r];
11            while (l <= r && sum * (r - l + 1) >= k) {
12                ans += (n - r); 
13                sum -= nums[l];
14                l++;
15            }
16            r++;
17        }
18        return (n * (n + 1) / 2) - ans;
19    }
20};
21