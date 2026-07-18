// Last updated: 7/18/2026, 2:07:56 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        string word = strs[0];
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            for (auto it : strs) {
                if (i >= it.size() || it[i] != ch)
                    return ans;
            }
            ans += ch;
        }

        return ans;
    }
};