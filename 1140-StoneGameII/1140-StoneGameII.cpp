// Last updated: 11/13/2026, 3:02:42 PM
1class Solution {
2public:
3    int dp[101][101];
4    int solve(int i, int M, vector<int>& suffix, int n) {
5        if (i >= n) return 0;
6        if (dp[i][M] != -1)
7            return dp[i][M];
8        int ans = 0;
9        for (int X = 1; X <= 2 * M; X++) {
10            if (i + X > n) break;
11            int newM = max(M, X);
12            int alice = suffix[i] - solve(i + X, newM, suffix, n);
13            ans = max(ans, alice);
14        }
15        return dp[i][M] = ans;
16    }
17
18    int stoneGameII(vector<int>& piles) {
19        int n = piles.size();
20        vector<int> suffix(n + 1, 0);
21        for (int i = n - 1; i >= 0; i--) {
22            suffix[i] = suffix[i + 1] + piles[i];
23        }
24        memset(dp, -1, sizeof(dp));
25        return solve(0, 1, suffix, n);
26    }
27};