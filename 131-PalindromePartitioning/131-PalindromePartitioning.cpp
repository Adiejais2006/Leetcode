// Last updated: 7/18/2026, 2:06:10 PM
class Solution {void func(int ind, vector<string> &temp, vector<vector<string>> &ans,
              string s) {
        if (ind == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int j = ind; j < s.size(); j++) {
            if (palindrome(s, ind, j)) {
                string subs = s.substr(ind, j - ind + 1);
                temp.push_back(subs);
                func(j + 1, temp, ans, s);
                temp.pop_back();
            }
        }
    }

    bool palindrome(string s, int ind, int j) {
        int start = ind;
        int end = j;
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
          vector<vector<string>> ans;
        vector<string> temp;
        func(0, temp, ans, s);
        return ans;
    }
};