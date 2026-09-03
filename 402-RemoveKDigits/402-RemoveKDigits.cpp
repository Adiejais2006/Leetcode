// Last updated: 9/3/2026, 3:58:25 PM
1class Solution {
2public:
3    string removeKdigits(string num, int k) {
4        stack<char> st;
5        for (char c : num) {
6            while (!st.empty() && k > 0 && st.top() > c) {
7                st.pop();
8                k--;
9            }
10            st.push(c);
11        }
12        while (!st.empty() && k > 0) {
13            st.pop();
14            k--;
15        }
16        string ans;
17        while (!st.empty()) {
18            ans += st.top();
19            st.pop();
20        }
21        reverse(ans.begin(), ans.end());
22        int i = 0;
23        while (i < ans.size() && ans[i] == '0')
24            i++;
25        return i == ans.size() ? "0" : ans.substr(i);
26    }
27};