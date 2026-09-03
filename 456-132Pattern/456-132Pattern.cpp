// Last updated: 9/3/2026, 6:48:27 PM
1class Solution {
2public:
3    bool find132pattern(vector<int>& nums) {
4        stack<int> st;
5        int second = INT_MIN;
6        int n = nums.size();
7        for (int i = n - 1; i >= 0; i--) {
8            while (!st.empty() && st.top() < nums[i]) {
9                second = st.top();
10                st.pop();
11            }
12            if (second != INT_MIN && nums[i] < second)
13                return true;
14            st.push(nums[i]);
15        }
16        return false;
17    }
18};