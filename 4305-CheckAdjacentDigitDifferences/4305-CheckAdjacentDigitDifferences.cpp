// Last updated: 7/18/2026, 1:58:39 PM
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {

        for (int i = 1; i < s.size(); i++) {
            if (abs(s[i] - s[i - 1]) > 2)
                return false;
        }

        return true;
    }
};