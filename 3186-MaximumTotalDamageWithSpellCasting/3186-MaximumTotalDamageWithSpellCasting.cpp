// Last updated: 10/23/2026, 2:36:22 PM
1class Solution {
2public:
3    long long maximumTotalDamage(vector<int>& power) {
4        sort(power.begin(), power.end());
5        vector<int> nums;
6        vector<long long> points;
7        for (int x : power) {
8            if (nums.empty() || nums.back() != x) {
9                nums.push_back(x);
10                points.push_back(x);
11            } else {
12                points.back() += x;
13            }
14        }
15        int n = nums.size();
16        vector<long long> dp(n, 0);
17        for (int i = 0; i < n; i++) {
18            long long take = points[i];
19            int j = upper_bound(nums.begin(), nums.begin() + i,
20                                nums[i] - 3) - nums.begin() - 1;
21            if (j >= 0)
22                take += dp[j];
23            long long skip = (i > 0) ? dp[i - 1] : 0;
24            dp[i] = max(take, skip);
25        }
26        return dp[n - 1];
27    }
28};