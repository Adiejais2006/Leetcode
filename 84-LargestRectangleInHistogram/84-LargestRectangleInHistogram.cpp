// Last updated: 7/18/2026, 2:06:52 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
               int n = heights.size();
        int maxu = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int curElement = heights[i];
            while (!st.empty() && heights[st.top()] > curElement) {
                int nse = i;
                int value = heights[st.top()];
                st.pop();
                int pse = -1;
                if (!st.empty()) pse = st.top();
                int area = (nse - pse - 1) * value;
                maxu = max(maxu, area);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = n;
            int value = heights[st.top()];
            st.pop();
            int pse = -1;
            if (!st.empty()) pse = st.top();
            int area = (nse - pse - 1) * value;
            maxu = max(maxu, area);
        }
        return maxu;
    }
};