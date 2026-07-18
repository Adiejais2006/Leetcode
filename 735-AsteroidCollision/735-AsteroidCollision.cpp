// Last updated: 7/18/2026, 2:03:33 PM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
         stack<int> st;
        vector<int> ans;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            int curElement = asteroids[i];

            while(!st.empty() && curElement <0 && st.top() >0 && abs(curElement) > st.top()){
                st.pop();
            }
            if (!st.empty() && curElement <0 && st.top() >0 && abs(curElement) < abs(st.top())) {
                continue;
            }

            if (!st.empty() && curElement <0 && st.top() >0 && abs(curElement) == abs(st.top())) {
                st.pop();
                continue;
            }
            st.push(asteroids[i]);
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};