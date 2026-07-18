// Last updated: 7/18/2026, 2:03:03 PM
class Solution { vector<int> nsee(vector<int> &arr) {
        int n = arr.size();
        vector<int> a(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            int currElement = arr[i];
            while (!st.empty() && arr[st.top()] >= currElement) {
                st.pop();
            }
            if (st.empty())
                a[i] = n;
            else
                a[i] = st.top();
            st.push(i);
        }
        return a;
    }

    vector<int> psee(vector<int> &arr) {
        int n = arr.size();
        vector<int> a(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int currElement = arr[i];
            while (!st.empty() && arr[st.top()] > currElement) {
                st.pop();
            }
            if (st.empty()) {
                a[i] = -1;
            } else {
                a[i] = st.top();
            }

            st.push(i);
        }

        return a;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
         long long mod = 1e9 + 7;
        vector<int> nse = nsee(arr);
        vector<int> pse = psee(arr);
        int n = arr.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + ((left * right) % mod) * arr[i] % mod) % mod;
        }

        return (int)sum;
    }
};