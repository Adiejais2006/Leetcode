// Last updated: 11/4/2026, 9:28:30 PM
1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        int n = asteroids.size();
5        stack<int> st;
6        for (int i = 0; i < n; i++) {
7            if (asteroids[i] > 0) {
8                st.push(asteroids[i]);
9            } else {
10
11                while (!st.empty() && st.top() > 0 &&
12                       st.top() < abs(asteroids[i]))
13                    st.pop();
14                if (st.empty() || st.top() < 0)
15                    st.push(asteroids[i]);
16                if (!st.empty() && st.top() == -asteroids[i]) {
17                    st.pop();
18                }
19            }
20        }
21        vector<int> ans;
22        while (!st.empty()) {
23            ans.push_back(st.top());
24            st.pop();
25        }
26        reverse(ans.begin(), ans.end());
27        return ans;
28    }
29};