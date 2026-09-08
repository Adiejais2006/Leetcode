// Last updated: 9/9/2026, 12:10:20 AM
1class Solution {
2public:
3    string removeDuplicates(string s) {
4        stack<char> st;
5        bool popped = false;
6        for (auto it : s) {
7            while (!st.empty() && it == st.top()) {
8                st.pop();
9                popped = true;
10            }
11            if (popped) {
12                popped = false;
13                continue;
14            }
15            st.push(it);
16        }
17
18        string ans = "";
19        while (!st.empty()) {
20            ans += st.top();
21            st.pop();
22        }
23        reverse(ans.begin(), ans.end());
24        return ans;
25    }
26};