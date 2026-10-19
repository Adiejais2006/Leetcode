// Last updated: 10/19/2026, 2:17:27 PM
1class Solution {
2    int func(int i, int m, int n, vector<pair<int, int>>& mpp,
3             vector<vector<vector<int>>> &dp) {
4        if (i == 0) {
5            if (mpp[i].first <= m && mpp[i].second <= n)
6                return dp[i][m][n] = 1;
7            return dp[i][m][n] =  0;
8        }
9        if (i < 0)
10            return 0;
11        if (dp[i][m][n] != -1)
12            return dp[i][m][n];
13        int nottake = func(i - 1, m, n, mpp, dp);
14        int take = 0;
15        if (mpp[i].first <= m && mpp[i].second <= n) {
16            take =
17                1 + func(i - 1, m - mpp[i].first, n - mpp[i].second, mpp, dp);
18        }
19        return dp[i][m][n] = max(take, nottake);
20    }
21
22public:
23    int findMaxForm(vector<string>& strs, int m, int n) {
24        int s = strs.size();
25        vector<pair<int, int>> ans; // index pr store krega 0 or 1
26        for (auto it : strs) {
27            int z = 0;
28            int o = 0;
29            for (auto a : it) {
30                if (a == '0')
31                    z++;
32                else
33                    o++;
34            }
35            ans.push_back({z, o});
36        }
37        vector<vector<vector<int>>> dp(
38            s, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
39        func(s - 1, m, n, ans, dp);
40        return dp[s - 1][m][n];
41    }
42};