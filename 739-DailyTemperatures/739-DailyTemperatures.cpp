// Last updated: 10/27/2026, 2:41:22 PM
1class Solution {
2    vector<int> nse(vector<int>& temperatures) {
3        int n = temperatures.size();
4        stack<int> st;
5        vector<int> ans(n);
6        for (int i = n - 1; i >= 0; i--) {
7            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
8                st.pop();
9            if (st.empty())
10                ans[i] = n;
11            else
12                ans[i] = st.top();
13            st.push(i);
14        }
15        return ans;
16    }
17public:
18    vector<int> dailyTemperatures(vector<int>& temperatures) {
19        int n = temperatures.size();
20        vector<int> ans(n);
21        vector<int> next = nse(temperatures);
22        for (int i = 0; i < n; i++) {
23            if (next[i] == n)
24                ans[i] = 0;
25            else
26                ans[i] = next[i] - i;
27        }
28        return ans;
29    }
30};