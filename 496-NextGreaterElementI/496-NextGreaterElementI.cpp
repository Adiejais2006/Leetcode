// Last updated: 10/29/2026, 3:02:13 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int n = nums1.size();
5        int m = nums2.size();
6        stack<int> st;
7        vector<int> temp(m);
8        vector<int> ans;
9        unordered_map<int,int>mpp;
10        for (int i = m - 1; i >= 0; i--) {
11            while (!st.empty() && st.top() < nums2[i])
12                st.pop();
13            if (st.empty())
14                temp[i] = -1;
15            else
16                temp[i] = st.top();
17            st.push(nums2[i]);
18            mpp[nums2[i]] = i ;
19        }
20        for(int i = 0  ; i<n ; i++){
21            int ind = mpp[nums1[i]];
22            ans.push_back(temp[ind]);
23        }
24        return ans;
25    }
26};