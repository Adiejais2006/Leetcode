// Last updated: 7/18/2026, 1:59:21 PM
class Solution {
public:
    string processStr(string s) {
        string ans = "";

        for (auto it : s) {
            if (isalpha(it))
                ans += it;
            else if (it == '*') {
                if (ans.size() > 0)
                    ans.pop_back();
            } else if (it == '#') {
                string a = ans;
                ans += a;
            } else if (it == '%')
                reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};