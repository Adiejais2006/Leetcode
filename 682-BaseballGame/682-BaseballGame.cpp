// Last updated: 7/18/2026, 2:03:47 PM
class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> st;

        for (string op : operations) {

            if (op == "C") {
                st.pop();

            } else if (op == "D") {
                st.push(2 * st.top());

            }

            else if (op == "+") {
                int first = st.top();
                st.pop();

                int second = st.top();
                int sum = first + second;

                st.push(first);

                st.push(sum);

            } else {
                st.push(stoi(op));
            }
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};