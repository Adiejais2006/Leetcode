// Last updated: 11/13/2026, 11:59:30 AM
1class Solution {
2public:
3    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
4        deque<int> starts;
5        long long ans = 0, water = 0;
6        int n = nums.size(), r = n - 1;
7        for (int l = n - 1; l >= 0; --l) {
8            int x = nums[l];
9            while (!starts.empty() && nums[starts.front()] <= x) {
10                int s = starts.front();
11                starts.pop_front();
12                int end = starts.empty() ? r + 1 : starts.front();
13                water += 1LL * (x - nums[s]) * (end - s);
14            }
15            starts.push_front(l);
16            while (water > k) { 
17                water -= nums[starts.back()] - nums[r];
18                if (starts.back() == r)
19                    starts.pop_back();
20                --r;
21            }
22            ans += r - l + 1;
23        }
24        return ans;
25    }
26};