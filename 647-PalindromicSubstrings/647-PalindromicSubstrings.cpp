// Last updated: 10/22/2026, 1:45:13 PM
1class Solution {
2
3    bool isPal(int i, int j, string& s, vector<vector<int>> &dp) {
4        if (i >= j)
5            return 1;
6        if (dp[i][j] != -1)
7            return dp[i][j];
8        if (s[i] == s[j]) {
9            return dp[i][j] = isPal(i + 1, j - 1, s, dp);
10        }
11        return dp[i][j] = 0;
12    }
13
14public:
15    int countSubstrings(string s) {
16        int n = s.size();
17        int cnt = 0;
18        vector<vector<int>> dp(n, vector<int>(n, -1));
19        for (int i = 0; i < n; i++) {
20            for (int j = i; j < n; j++) {
21                if (isPal(i, j, s, dp))
22                    cnt++;
23            }
24        }
25        return cnt;
26    }
27};