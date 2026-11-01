// Last updated: 11/1/2026, 4:53:55 PM
1class Solution {
2    vector<int> nse(vector<int>& nums) {
3        int n = nums.size();
4        stack<int> st;
5        vector<int> ans(n);
6        for (int i = n - 1; i >= 0; i--) {
7            while (!st.empty() && nums[st.top()] >= nums[i])
8                st.pop();
9            if (st.empty())
10                ans[i] = n;
11            else
12                ans[i] = st.top();
13            st.push(i);
14        }
15        return ans;
16    }
17    vector<int> pse(vector<int>& nums) {
18        int n = nums.size();
19        stack<int> st;
20        vector<int> ans(n);
21        for (int i = 0; i < n; i++) {
22            while (!st.empty() && nums[st.top()] > nums[i])
23                st.pop();
24            if (st.empty())
25                ans[i] = -1;
26            else
27                ans[i] = st.top();
28            st.push(i);
29        }
30        return ans;
31    }
32
33public:
34    int largestRectangleArea(vector<int>& heights) {
35        int n = heights.size();
36        vector<int> forwardsmaller = nse(heights);
37        vector<int> backsmaller = pse(heights);
38        int ans = 0;
39        for (int i = 0; i < n; i++) {
40            int right = forwardsmaller[i] - i;
41            int left = i - backsmaller[i];
42            int contribution = (right + left - 1) * heights[i];
43            ans = max(ans, contribution);
44        }
45        return ans;
46    }
47};