// Last updated: 7/18/2026, 2:04:18 PM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> st;
        
        for (int x : nums2) {
            while (!st.empty() && st.top() < x) {
                m[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        
        vector<int> ans;
        for (int x : nums1) {
            if (m.count(x)) {
                ans.push_back(m[x]);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};