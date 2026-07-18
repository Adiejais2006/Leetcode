// Last updated: 7/18/2026, 2:08:06 PM
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1)
            return s;
        vector<string> rows(numRows);
        int crow = 0;
        bool down = true;
        for (int i = 0; i < s.size(); i++) {
            rows[crow] += s[i];
            if (crow == 0)
                down = true;
            if (crow == numRows - 1)
                down = false;

            if (down)
                crow++;
            else
                crow--;
        }
        string ans;
        for (auto it : rows) {
            ans += it;
        }

        return ans;
    }
};