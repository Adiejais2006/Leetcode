// Last updated: 7/18/2026, 2:06:25 PM
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<unsigned long long> before(m + 1, 0),
                                   curr(m + 1, 0);

        before[0] = 1;

        for (int i = 1; i <= n; i++) {
            curr[0] = 1;

            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = before[j - 1] + before[j];
                } else {
                    curr[j] = before[j];
                }
            }

            before = curr;
        }

        return before[m];
    }
};