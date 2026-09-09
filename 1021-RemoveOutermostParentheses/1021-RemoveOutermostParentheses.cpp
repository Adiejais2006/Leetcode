// Last updated: 9/9/2026, 1:19:53 PM
1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        stack<char> st;
5        string ans = "";
6        for (char ch : s) {
7            if (ch == '(') {
8                if (!st.empty()) {
9                    ans += ch;
10                }
11                st.push(ch);
12            }
13            else {
14                st.pop();
15                if (!st.empty()) {
16                    ans += ch;
17                }
18            }
19        }
20        return ans;
21    }
22};