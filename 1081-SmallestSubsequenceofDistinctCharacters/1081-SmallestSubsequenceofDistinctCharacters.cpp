// Last updated: 7/19/2026, 9:58:23 PM
1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        unordered_map<char, int> mpp;
5        for (auto it : s) {
6            mpp[it]++;
7        }
8        stack<int> st;
9        vector<bool> inStack(26);
10        for (auto it : s) {
11            mpp[it]--;
12            if (inStack[it - 'a'])
13                continue;
14            while (!st.empty() && st.top() > it && mpp[st.top()] > 0) {
15                inStack[st.top() - 'a'] = false;
16                st.pop();
17            }
18
19            st.push(it);
20            inStack[it - 'a'] = true;
21        }
22        string ans = "";
23        while (!st.empty()) {
24            ans += st.top();
25            st.pop();
26        }
27        reverse(ans.begin(), ans.end());
28        return ans;
29    }
30};