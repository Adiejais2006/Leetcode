// Last updated: 11/15/2026, 1:48:11 PM
1class Solution {
2public:
3    int numSplits(string s) {
4        int n = s.size();
5        vector<int> prefixunique(n, 0);
6        vector<int> suffixunique(n, 0);
7        unordered_set<char> st;
8        for (int i = 0; i < n; i++) {
9            st.insert(s[i]);
10            prefixunique[i] = st.size();
11        }
12        st.clear();
13        for (int i = n - 1; i >= 0; i--) {
14            st.insert(s[i]);
15            suffixunique[i] = st.size();
16        }
17        int ans = 0;
18        for (int i = 1; i < n; i++) {
19            if (prefixunique[i - 1] == suffixunique[i])
20                ans++;
21        }
22        return ans;
23    }
24};