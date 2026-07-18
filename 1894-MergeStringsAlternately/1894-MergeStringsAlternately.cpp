// Last updated: 7/18/2026, 2:01:32 PM
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string ans = "";
        int i = 0;
        int j = 0;
        bool turn = true;
        while (i < n && j < m) {
            if (turn) {
                ans += word1[i++];
                turn = false;
            } else {
                ans += word2[j++];
                turn = true;
            }
        }
        while (i < n) {
            ans += word1[i++];
        }
        while (j < m) {
            ans += word2[j++];
        }
        return ans;
    }
};