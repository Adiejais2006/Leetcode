// Last updated: 10/3/2026, 12:45:18 PM
1class Solution {
2public:
3    int longestValidParentheses(string s) {
4        stack<int> st;
5        int res = 0;
6        st.push(-1);
7
8        for (int i = 0; i < s.size(); i++) {
9            if (s[i] == '(') {
10                st.push(i);
11            } else {
12                st.pop();
13                if (st.empty())
14                    st.push(i);
15                else
16                    res = max(res, i - st.top());
17            }
18        }
19        return res;
20    }
21};
22