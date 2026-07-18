// Last updated: 7/18/2026, 2:05:52 PM
class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int value) {
        long long val = value;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2 * val - mini);  // safe now
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();

        if (x >= mini) {
            return (int)x;
        } else {
            return (int)mini;
        }
    }

    int getMin() {
        if (st.empty()) return -1;
        return (int)mini;
    }
};