// Last updated: 8/3/2026, 11:11:26 PM
1class Solution {
2public:
3    static constexpr int MIN = -50000001;
4    static inline string s[] = {"Bob", "Tie", "Alice"};
5
6    string stoneGameIII(vector<int>& A) {
7        int n = A.size();
8        vector<int> dp(n, MIN);
9
10        auto maxDiff = [&](this auto&& maxDiff, int i) -> int {
11            if (i == n) return 0;
12
13            int& res = dp[i];
14            if (res != MIN) return res;
15
16            int sum = 0;
17
18            for (int j = 1; j <= 3 && i + j <= n; j++) {
19                sum += A[i + j - 1];
20                res = max(res, sum - maxDiff(i + j));
21            }
22
23            return res;
24        };
25
26        int d = maxDiff(0);
27        return s[(d > 0) - (d < 0) + 1];
28    }
29};