// Last updated: 9/2/2026, 11:25:36 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        stack<int> st;
5        int n = nums2.size();
6        vector<int> nge(n);
7        for (int i = n - 1; i >= 0; i--) {
8            while (!st.empty() && nums2[st.top()] <= nums2[i])
9                st.pop();
10            if (st.empty())
11                nge[i] = -1;
12            else
13                nge[i] = nums2[st.top()];
14            st.push(i);
15        }
16        unordered_map<int, int> mpp;
17        for (int i = 0; i < n; i++) {
18            mpp[nums2[i]] = i;
19        }
20        vector<int> ans;
21        for (auto it : nums1) {
22            ans.push_back(nge[mpp[it]]);
23        }
24        return ans;
25    }
26};