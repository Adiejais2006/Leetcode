// Last updated: 9/4/2026, 12:43:36 AM
1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4        unordered_map<char, int> mpp;
5        for (auto it : s) {
6            mpp[it]++;
7        }
8        stack<char> st;
9        vector<int> a(26);
10        string ans = "";
11        for (auto it : s) {
12            mpp[it]--;
13            if (a[it - 'a'])
14                continue;
15            while (!st.empty() && mpp[st.top()] > 0 && st.top() > it) {
16                a[st.top() - 'a'] = false;
17                st.pop();
18            }
19            st.push(it);
20            a[it - 'a'] = true;
21        }
22
23        while (!st.empty()) {
24            ans += st.top();
25            st.pop();
26        }
27        reverse(ans.begin(), ans.end());
28        return ans;
29    }
30};