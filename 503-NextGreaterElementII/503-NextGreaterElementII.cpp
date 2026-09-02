// Last updated: 9/2/2026, 11:38:58 PM
1class Solution {
2public:
3    vector<int> nextGreaterElements(vector<int>& nums) {
4        int n = nums.size();
5        stack<int> st;
6        vector<int> ans(n);
7        for (int i = 2 * n - 1; i >= 0; i--) {
8
9            while (!st.empty() && st.top() <= nums[i%n]) {
10                st.pop();
11            }
12            if (st.empty())
13                ans[i%n] = -1;
14            else
15               ans[i%n] = st.top();
16           st.push(nums[i%n]);
17        }
18        return ans;
19    }
20};