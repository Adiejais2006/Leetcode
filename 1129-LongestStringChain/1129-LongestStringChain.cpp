// Last updated: 7/18/2026, 2:02:34 PM
class Solution {    static bool comapre(string a , string b){
        return (a.size()<b.size());
    }
    bool check(string s1, string s2) {
        if (s1.size() != s2.size() + 1) return false;
        int i = 0;
        int j = 0;
        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if (i == s1.size() && j == s2.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
         int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        sort(words.begin(),words.end(), comapre);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
                if (dp[i] > maxi) maxi = dp[i];
            }
        }
        return maxi;
    }
};