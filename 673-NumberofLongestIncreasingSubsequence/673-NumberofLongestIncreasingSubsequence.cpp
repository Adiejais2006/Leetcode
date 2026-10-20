// Last updated: 10/20/2026, 8:57:48 PM
1class Solution {
2public:
3    int findNumberOfLIS(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> dp(n, 1);
6        vector<int> count(n, 1);
7        int maxi = 1;
8        for (int i = 0; i < n; i++) {
9            int cnt = 0;
10            for (int j = 0; j < i; j++) {
11                if (nums[i] > nums[j]) {
12                    if (dp[i] < dp[j] + 1) {
13                        dp[i] = dp[j] + 1;
14                        count[i] = count[j];
15                    }
16
17                    else if (dp[i] == dp[j] + 1)
18                        count[i] += count[j];
19                }
20            }
21            if (dp[i] > maxi) {
22                maxi = dp[i];
23            }
24        }
25        int cnt = 0;
26        for (int i = 0; i < n; i++) {
27            if (dp[i] == maxi)
28                cnt += count[i];
29        }
30        return cnt;
31    }
32};