// Last updated: 9/3/2026, 3:56:46 PM
1class Solution {
2public:
3    string removeKdigits(string num, int k) {
4        stack<int> st;
5        for (auto it : num) {
6            while (!st.empty() && k > 0 && st.top() > it) {
7                st.pop();
8                k--;
9            }
10            st.push(it);
11        }
12        if (st.empty())
13            return "0";
14        while(!st.empty() && k>0){st.pop();k--;}
15        string ans = "";
16        while (!st.empty()) {
17            ans += st.top();
18            st.pop();
19        }
20        reverse(ans.begin(), ans.end());
21        int nonzero = 0;
22        for (auto it : ans) {
23            if (it != '0')
24                nonzero++;
25        }
26
27        if (nonzero == 0)
28            return "0";
29        int i = 0;
30        while (ans[i] == '0') {
31            i++;
32        }
33        return ans.substr(i);
34    }
35};