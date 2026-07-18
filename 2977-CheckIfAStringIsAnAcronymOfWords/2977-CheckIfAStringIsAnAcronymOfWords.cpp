// Last updated: 7/18/2026, 2:00:00 PM
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {

        string check = "";
        for (auto it : words) {

            check += it[0];
        }
        if (check == s)
            return true;
        return false;
    }
};