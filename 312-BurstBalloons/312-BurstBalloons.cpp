// Last updated: 10/21/2026, 4:56:45 PM
1class Solution {
2public:
3    int maxCoins(vector<int>& nums) {
4         int n = nums.size();
5
6        vector<int> arr;
7        arr.push_back(1);
8
9        for (int x : nums) {
10            arr.push_back(x);
11        }
12
13        arr.push_back(1);
14
15        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
16
17        for (int i = n; i >= 1; i--) {
18            for (int j = 1; j <= n; j++) {
19
20                int maxi = 0;
21
22                for (int k = i; k <= j; k++) {
23
24                    int cost = arr[i - 1] * arr[k] * arr[j + 1] +
25                               dp[i][k - 1] +
26                               dp[k + 1][j];
27
28                    maxi = max(maxi, cost);
29                }
30
31                dp[i][j] = maxi;
32            }
33        }
34
35        return dp[1][n];
36    }
37};