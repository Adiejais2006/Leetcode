// Last updated: 7/18/2026, 2:04:43 PM
class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        if (k == n)
            return "0";
        string ans = "";
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char currElement = nums[i];
            while (!st.empty() && k > 0 && st.top() > currElement) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int ind = 0;
        while (ind < ans.size() && ans[ind] == '0')
            ind++;
        ans = ans.substr(ind);
        if (ans == "")
            return "0";
        return ans;
    }
};