// Last updated: 9/14/2026, 1:18:47 PM
1class Solution {
2public:
3    string processStr(string s) {
4        string ans = "";
5
6        for (auto it : s) {
7            if (isalpha(it))
8                ans += it;
9            else if (it == '*') {
10                if (ans.size() > 0)
11                    ans.pop_back();
12            } else if (it == '#') {
13                string a = ans;
14                ans += a;
15            } else if (it == '%')
16                reverse(ans.begin(), ans.end());
17        }
18
19        return ans;
20    }
21};