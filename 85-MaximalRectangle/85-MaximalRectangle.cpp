// Last updated: 9/3/2026, 8:11:29 PM
1
2class Solution {
3    vector<int> ns(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n);
6        stack<int> st;
7        for (int i = n - 1; i >= 0; i--) {
8            while (!st.empty() && nums[st.top()] >= nums[i]) {
9                st.pop();
10            }
11            if (st.empty())
12                ans[i] = n;
13            else
14                ans[i] = st.top();
15            st.push(i);
16        }
17        return ans;
18    }
19    vector<int> ps(vector<int>& nums) {
20        int n = nums.size();
21        vector<int> ans(n);
22        stack<int> st;
23        for (int i = 0; i < n; i++) {
24            while (!st.empty() && nums[st.top()] >= nums[i]) {
25                st.pop();
26            }
27            if (st.empty())
28                ans[i] = -1;
29            else
30                ans[i] = st.top();
31            st.push(i);
32        }
33        return ans;
34    }
35    int largestRectangleArea(vector<int>& nums) {
36        int n = nums.size();
37        vector<int> nse = ns(nums);
38        vector<int> pse = ps(nums);
39        int ans = 0;
40        for (int i = 0; i < n; i++) {
41            int w = nse[i] - pse[i] - 1;
42            int h = nums[i];
43            int area = h * w;
44            ans = max(ans, area);
45        }
46        return ans;
47    }
48
49public:
50    int maximalRectangle(vector<vector<char>>& nums) {
51        int n = nums.size();
52        int m = nums[0].size();
53        vector<int> heights(m, 0);
54        int ans = 0;
55        for (int i = 0; i < n; i++) {
56            for (int j = 0; j < m; j++) {
57                if (nums[i][j] == '1')
58                    heights[j]++;
59                else
60                    heights[j] = 0;
61            }
62            ans = max(ans, largestRectangleArea(heights));
63        }
64        return ans;
65    }
66};