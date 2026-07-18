// Last updated: 7/18/2026, 2:00:47 PM
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int ans = 0;
        stack<pair<int, int>> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int cur = 0;

            while (!st.empty() && nums[i] > st.top().first) {
                cur = max(cur + 1, st.top().second);
                st.pop();
            }

            ans = max(ans, cur);
            st.push({nums[i], cur});
        }

        return ans;
    }
};