// Last updated: 10/20/2026, 8:59:46 PM
1
2class Solution {
3public:
4    int findNumberOfLIS(vector<int>& nums) {
5        int n = nums.size();
6        vector<int> dp(n, 1);
7        vector<int> count(n, 1);
8        int maxLen = 1;
9        for (int i = 0; i < n; i++) {
10            for (int j = 0; j < i; j++) {
11                if (nums[j] < nums[i]) {
12                    if (dp[j] + 1 > dp[i]) {
13                        dp[i] = dp[j] + 1;
14                        count[i] = count[j];
15                    }
16                    else if (dp[j] + 1 == dp[i]) {
17                        count[i] += count[j];
18                    }
19                }
20            }
21            maxLen = max(maxLen, dp[i]);
22        }
23        int ans = 0;
24        for (int i = 0; i < n; i++) {
25            if (dp[i] == maxLen) {
26                ans += count[i];
27            }
28        }
29        return ans;
30    }
31};
32
33