// Last updated: 9/3/2026, 8:45:24 PM
1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        stack<int> st;
5        for (auto a : asteroids) {
6            if (a > 0)
7                st.push(a);
8            else {
9                while (!st.empty() && st.top() > 0 && st.top() < abs(a)) {
10                    st.pop();
11                }
12                if (st.empty() || st.top() < 0)
13                    st.push(a);
14                if (!st.empty() && st.top() == -a) {
15                    st.pop();
16                }
17            }
18        }
19        int size = st.size();
20        vector<int> ans(size);
21        int i = size-1;
22        while (!st.empty()) {
23            ans[i--] = st.top();
24            st.pop();
25        }
26        return ans;
27    }
28};