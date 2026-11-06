// Last updated: 11/6/2026, 6:43:28 PM
1class Solution {void func(int ind, vector<string> &temp, vector<vector<string>> &ans,
2              string s) {
3        if (ind == s.size()) {
4            ans.push_back(temp);
5            return;
6        }
7        for (int j = ind; j < s.size(); j++) {
8            if (palindrome(s, ind, j)) {
9                string subs = s.substr(ind, j - ind + 1);
10                temp.push_back(subs);
11                func(j + 1, temp, ans, s);
12                temp.pop_back();
13            }
14        }
15    }
16
17    bool palindrome(string s, int ind, int j) {
18        int start = ind;
19        int end = j;
20        while (start <= end) {
21            if (s[start++] != s[end--]) return false;
22        }
23        return true;
24    }
25
26public:
27    vector<vector<string>> partition(string s) {
28          vector<vector<string>> ans;
29        vector<string> temp;
30        func(0, temp, ans, s);
31        return ans;
32    }
33};