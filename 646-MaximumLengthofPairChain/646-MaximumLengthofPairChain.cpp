// Last updated: 10/23/2026, 4:56:17 PM
1class Solution {
2    int func(int i, int prev, vector<vector<int>>& pairs,
3             vector<vector<int>>& dp) {
4        if (i == pairs.size())
5            return 0;
6        if (dp[i][prev+1] != -1)
7            return dp[i][prev+1];
8        int nottake = func(i + 1, prev, pairs, dp);
9        int take = 0;
10        if (prev == -1 || pairs[prev][1] < pairs[i][0]) {
11            take = 1 + func(i + 1, i, pairs, dp);
12        }
13        return dp[i][prev+1] = max(take, nottake);
14    }
15
16public:
17    int findLongestChain(vector<vector<int>>& pairs) {
18        int n = pairs.size();
19        sort(pairs.begin(), pairs.end());
20        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
21        return func(0, -1, pairs, dp);
22    }
23};