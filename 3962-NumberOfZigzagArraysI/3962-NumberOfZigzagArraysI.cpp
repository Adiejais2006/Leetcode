// Last updated: 7/18/2026, 1:59:19 PM
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        vector<long long> dp(m, 1);

        for (int i = 1; i < n; i++) {

            vector<long long> ndp(m);

            if (i & 1) {  // up move
                long long pref = 0;

                for (int v = 0; v < m; v++) {
                    long long cur = dp[v];
                    ndp[v] = pref;
                    pref = (pref + cur) % MOD;
                }
            } else {      // down move
                long long suff = 0;

                for (int v = m - 1; v >= 0; v--) {
                    long long cur = dp[v];
                    ndp[v] = suff;
                    suff = (suff + cur) % MOD;
                }
            }

            dp = move(ndp);
        }

        long long ans = 0;
        for (auto x : dp)
            ans = (ans + x) % MOD;

        return (ans * 2) % MOD;
    }
};