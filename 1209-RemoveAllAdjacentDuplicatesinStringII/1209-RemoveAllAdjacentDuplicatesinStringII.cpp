// Last updated: 11/5/2026, 3:15:17 PM
1class Solution {
2public:
3    string removeDuplicates(string s, int k) {
4
5        stack<pair<char, int>> st;
6        for (int i = 0; i < s.size(); i++) {
7            if (!st.empty() && st.top().first == s[i]) {
8                st.push({s[i], st.top().second + 1});
9            } else {
10                st.push({s[i], 1});
11            }
12            if (st.top().second == k)
13                for (int i = 0; i < k; i++) {
14                    st.pop();
15                }
16        }
17        string ans = "";
18        while (!st.empty()) {
19            ans += st.top().first;
20            st.pop();
21        }
22        reverse(ans.begin(), ans.end());
23        return ans;
24    }
25};