// Last updated: 10/23/2026, 5:01:38 PM
1class Solution {
2
3public:
4    int findLongestChain(vector<vector<int>>& pairs) {
5        int n = pairs.size();
6        sort(pairs.begin(), pairs.end());
7        vector<vector<int>> dp(n + 1, vector<int>(n + 1,0));
8        for (int i = n - 1; i >= 0; i--) {
9            for (int prev = n - 1; prev >= -1; prev--) {
10                int nottake = dp[i + 1][prev+1];
11                int take = 0;
12                if (prev == -1 || pairs[prev][1] < pairs[i][0]) {
13                    take = 1 + dp[i + 1][i+1];
14                }
15                dp[i][prev + 1] = max(take, nottake);
16            }
17        }
18        return dp[0][-1 + 1];
19    }
20};