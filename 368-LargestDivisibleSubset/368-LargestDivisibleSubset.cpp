// Last updated: 10/21/2026, 11:25:48 PM
1class Solution {
2public:
3    vector<int> largestDivisibleSubset(vector<int>& nums) {
4        int n = nums.size();
5        if (n == 0) return {};
6
7        sort(nums.begin(), nums.end());
8
9        vector<int> dp(n, 1);
10        vector<int> parent(n);
11
12        for (int i = 0; i < n; i++)
13            parent[i] = i;
14
15        int maxi = 1;
16        int lastIndex = 0;
17
18        for (int i = 0; i < n; i++) {
19            for (int j = 0; j < i; j++) {
20                if (nums[i] % nums[j] == 0) {
21                    if (dp[j] + 1 > dp[i]) {
22                        dp[i] = 1 + dp[j];
23                        parent[i] = j;
24                    }
25                }
26            }
27
28            if (dp[i] > maxi) {
29                maxi = dp[i];
30                lastIndex = i;
31            }
32        }
33
34        vector<int> ans;
35
36        while (parent[lastIndex] != lastIndex) {
37            ans.push_back(nums[lastIndex]);
38            lastIndex = parent[lastIndex];
39        }
40
41        ans.push_back(nums[lastIndex]);
42        reverse(ans.begin(), ans.end());
43
44        return ans;
45    }
46};