// Last updated: 7/18/2026, 2:06:58 PM
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, have;

        for (char c : t) need[c]++;

        int required = need.size();
        int formed = 0;

        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            have[c]++;

            if (need.count(c) && have[c] == need[c])
                formed++;

            while (formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                have[leftChar]--;

                if (need.count(leftChar) &&
                    have[leftChar] < need[leftChar])
                    formed--;

                l++;
            }
        }

        return minLen == INT_MAX
                   ? ""
                   : s.substr(start, minLen);
    }
};