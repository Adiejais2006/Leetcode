// Last updated: 7/18/2026, 2:00:59 PM
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
    long long sumSubarrayMins(vector<int> &arr) {
       
        vector<int> nse = nsee(arr);
        vector<int> pse = psee(arr);
        int n = arr.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + ((left * right) ) * arr[i] );
        }

        return sum;
    }

    vector<int> nge(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> pge(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }
    long long sumSubarrayMax(vector<int> &arr) {
       
        vector<int> pgee = pge(arr);
        vector<int> ngee = nge(arr);
        int n = arr.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = ngee[i] - i;
            sum = (sum + ((left * right) ) * arr[i])  ;
        }
        return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
         long long maximum = sumSubarrayMax(nums);
        long long minimum = sumSubarrayMins(nums);

        return maximum-minimum;
    }
};