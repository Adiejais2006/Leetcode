// Last updated: 9/3/2026, 9:35:18 PM
1class Solution {
2public:
3    string simplifyPath(string path) {
4        stack<string> st;
5        string curr;
6        for (char c : path) {
7            if (c != '/') {
8                curr += c;
9                continue;
10            }
11            if (curr == "..") {
12                if (!st.empty())
13                    st.pop();
14            } else if (!curr.empty() && curr != ".") {
15                st.push(curr);
16            }
17            curr = "";
18        }
19        if (curr == "..") {
20            if (!st.empty())
21                st.pop();
22        } else if (!curr.empty() && curr != ".") {
23            st.push(curr);
24        }
25        string ans;
26        while (!st.empty()) {
27            ans = "/" + st.top() + ans;
28            st.pop();
29        }
30        return ans.empty() ? "/" : ans;
31    }
32};