// Last updated: 10/28/2026, 6:16:28 PM
1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int n = nums.size();
5        stack<int> st;
6        vector<int> ans(n);
7        for (int i = 2 * n - 1; i >= 0; i--) {
8            while (!st.empty() && st.top() <= nums[i % n]) {
9                st.pop();
10            }
11            if (st.empty())
12                ans[i % n] = -1;
13            else
14                ans[i % n] = st.top();
15            st.push(nums[i % n]);
16        }
17        return ans;
18    }
19};