// Last updated: 7/18/2026, 2:02:13 PM
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;

        while (s.size() > 1) {
            int i = s.size() - 1;

            while (i > 0 && s[i] != s[0]) i--;

            if (i == 0) {
                ans += s.size() / 2;
                s.erase(s.begin());
            } else {
                ans += s.size() - 1 - i;
                s.erase(s.begin() + i);
                s.erase(s.begin());
            }
        }

        return ans;
    }
};