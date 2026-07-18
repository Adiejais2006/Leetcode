// Last updated: 7/18/2026, 2:03:59 PM
class Solution {
public:
    int minDistance(string str1, string str2) {
         int n = str1.size();
        int m = str2.size();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        int lcs = prev[m];
        int extra = abs(n-m);
        if(n>m){
            int change = 2*(m - lcs)+extra;
            return change;
        }
        else {
             int change = 2*(n - lcs)+extra;
            return change;
        }
    }
};