// Last updated: 9/3/2026, 3:58:46 PM
1class Solution {
2public:
3    string removeKdigits(string num, int k) {
4        string st;
5
6        for (char c : num) {
7            while (!st.empty() && k > 0 && st.back() > c) {
8                st.pop_back();
9                k--;
10            }
11            st.push_back(c);
12        }
13
14        while (k > 0) {
15            st.pop_back();
16            k--;
17        }
18
19        int i = 0;
20        while (i < st.size() && st[i] == '0')
21            i++;
22
23        return i == st.size() ? "0" : st.substr(i);
24    }
25};