// Last updated: 11/6/2026, 6:44:02 PM
1class Solution {
2    void func(int ind, vector<string>& temp, vector<vector<string>>& ans,
3              string s) {
4        if (ind == s.size()) {
5            ans.push_back(temp);
6            return;
7        }
8        for (int j = ind; j < s.size(); j++) {
9            if (palindrome(s, ind, j)) {
10                string subs = s.substr(ind, j - ind + 1);
11                temp.push_back(subs);
12                func(j + 1, temp, ans, s);
13                temp.pop_back();
14            }
15        }
16    }
17
18    bool palindrome(string s, int ind, int j) {
19        int start = ind;
20        int end = j;
21        while (start <= end) {
22            if (s[start++] != s[end--])
23                return false;
24        }
25        return true;
26    }
27
28public:
29    vector<vector<string>> partition(string s) {
30        vector<vector<string>> ans;
31        vector<string> temp;
32        func(0, temp, ans, s);
33        return ans;
34    }
35};