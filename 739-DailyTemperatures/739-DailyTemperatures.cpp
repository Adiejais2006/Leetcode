// Last updated: 9/2/2026, 9:01:20 PM
1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n);
6        stack<int> st;
7        for (int i = n - 1; i >= 0; i--) {
8            while (!st.empty() && nums[st.top()] <= nums[i]) {
9                st.pop();
10            }
11            if (st.empty())
12                ans[i] = 0;
13            else
14                ans[i] = st.top() - i;
15            st.push(i);
16        }
17        return ans;
18    }
19};