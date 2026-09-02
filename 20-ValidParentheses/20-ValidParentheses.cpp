// Last updated: 9/2/2026, 6:42:03 PM
1class Solution {
2    bool verify(char a, stack<char>& st) {
3        if(st.empty()) return false;
4        if (a == ')' && st.top() == '(')
5            return true;
6        else if (a == ']' && st.top() == '[')
7            return true;
8        else if (a == '}' && st.top() == '{')
9            return true;
10        return false;
11    }
12
13public:
14    bool isValid(string s) {
15        stack<char> st;
16        for (auto it : s) {
17            if (it == '(')
18                st.push(it);
19            else if (it == '{')
20                st.push(it);
21            else if (it == '[')
22                st.push(it);
23            else {
24                if (verify(it, st)) {
25                    st.pop();
26                    continue;
27                } else
28                    return false;
29            }
30        }
31        return (st.empty());
32       
33    }
34};