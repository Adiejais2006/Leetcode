// Last updated: 9/25/2026, 5:08:38 PM
1class Solution {
2
3public:
4    int uniquePaths(int m, int n) {
5        vector<int> prev(n, 1);
6        vector<int> curr(n, 1);
7        for (int i = 1; i < m; i++) {
8            for (int j = 1; j < n; j++) {
9                int up = prev[j];
10                int left = curr[j - 1];
11                curr[j] = up + left;
12                prev = curr;
13            }
14        }
15        return prev[n - 1];
16    }
17};