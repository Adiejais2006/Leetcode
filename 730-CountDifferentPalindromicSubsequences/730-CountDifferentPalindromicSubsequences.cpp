// Last updated: 7/18/2026, 2:03:36 PM
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        long mod = 1e9 + 7;
        vector<vector<long>> dp(n, vector<long>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int low = i + 1, high = j - 1;
                    while (low <= high && s[low] != s[i]) low++;
                    while (low <= high && s[high] != s[i]) high--;
                    if (low > high) dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    else if (low == high) dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    else dp[i][j] = dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
                dp[i][j] = (dp[i][j] + mod) % mod;
            }
        }
        return (int)dp[0][n - 1];
    }
};