// Last updated: 10/23/2026, 2:31:33 PM
1class Solution {
2public:
3    long long maximumTotalDamage(vector<int>& power) {
4        sort(power.begin(), power.end());
5
6        vector<int> nums;
7        vector<long long> points;
8        for (int x : power) {
9            if (nums.empty() || nums.back() != x) {
10                nums.push_back(x);
11                points.push_back(x);
12            } else {
13                points.back() += x;
14            }
15        }
16        int n = nums.size();
17        vector<long long> dp(n, 0);
18        for (int i = 0; i < n; i++) {
19            long long nottake = (i > 0) ? dp[i - 1] : 0;
20            int j = upper_bound(nums.begin(), nums.begin() + i,
21                                nums[i] - 3) - nums.begin() - 1;
22
23            long long take = points[i];
24            if (j >= 0)
25                take += dp[j];
26            dp[i] = max(take, nottake);
27        }
28        return dp[n - 1];
29    }
30};