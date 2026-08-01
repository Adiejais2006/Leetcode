// Last updated: 8/1/2026, 11:07:35 PM
1class Solution {
2public:
3    bool predictTheWinner(vector<int>& A) {
4        int n = A.size();
5        if (~n & 1) return true;
6
7        vector dp(n, vector<int>(n, -1));
8        auto maxDiff = [&](this auto&& maxDiff, int i, int j) -> int {
9            int& res = dp[i][j];
10            if (res != -1) return res;
11            if (i == j) return res = A[i];
12
13            return res = max(A[i] - maxDiff(i + 1, j),
14                             A[j] - maxDiff(i, j - 1));
15        };
16
17        return maxDiff(0, n - 1) >= 0;
18    }
19};