// Last updated: 7/18/2026, 2:01:16 PM
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = words.size();
            string ans = "";
        for (int i = 0; i < n; i++) {
            ans += words[i];
            if (ans == s)
                return true;
                if(ans.size() > s.size()) return false;
        }
        return false;
    }
};