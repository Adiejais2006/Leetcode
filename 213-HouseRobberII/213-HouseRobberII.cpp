// Last updated: 9/24/2026, 6:33:45 PM
1class Solution {
2    int memo(int i, int end, vector<int>& nums, vector<int>& dp) {
3        int n = i - end + 1;
4        dp[end] = nums[end];
5        if (n == 1)
6            return dp[end];
7        dp[end + 1] = max(nums[end], nums[end + 1]);
8        for (int j = end + 2; j <= i; j++) {
9            int nottake = dp[j - 1];
10            int take = nums[j] + dp[j - 2];
11            dp[j] = max(take, nottake);
12        }
13        return dp[i];
14    }
15
16public:
17    int rob(vector<int>& nums) {
18        int n = nums.size();
19
20        if (n == 1)
21            return nums[0];
22
23        vector<int> dp1(n, -1);
24        vector<int> dp2(n, -1);
25
26        // Skip last → [0 ... n-2]
27        int skipLast = memo(n - 2, 0, nums, dp1);
28
29        // Skip first → [1 ... n-1]
30        int skipFirst = memo(n - 1, 1, nums, dp2);
31
32        return max(skipFirst, skipLast);
33    }
34};