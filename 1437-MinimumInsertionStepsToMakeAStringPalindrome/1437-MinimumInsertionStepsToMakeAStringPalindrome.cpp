// Last updated: 7/18/2026, 2:02:06 PM
class Solution {        int lcs(string &a, string &b) {
            int n = a.size();
            int m = b.size();
            vector<vector<int>>dp(n + 1, vector<int>(m + 1));
            for(int i = 0 ; i<n+1; i++){
                dp[i][0] = 0;
            }
            for(int i = 0 ; i<m+1; i++){
                dp[0][i] = 0;
            }
            for (int ind1 = 1; ind1 < n + 1; ind1++) {
                for (int ind2 = 1; ind2 < m + 1; ind2++) {
                    if (a[ind1 - 1] == b[ind2 - 1])
                        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                    else
                        dp[ind1][ind2] =
                            max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }

            return dp[n][m];
        }

    
public:
    int minInsertions(string s) {
         string p = s;
        reverse(p.begin(),p.end());
        int a = lcs(s,p);
        return (s.size()-a);
    }
};