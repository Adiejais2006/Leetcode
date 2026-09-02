// Last updated: 9/2/2026, 6:49:09 PM
1class MinStack {
2    stack<int> st;
3    stack<int> minVal;
4
5public:
6    MinStack() {}
7
8    void push(int value) {
9        st.push(value);
10        if (minVal.empty()) {
11            minVal.push(value);
12        } else {
13            int curr = minVal.top();
14            minVal.push(min(value, curr));
15        }
16    }
17
18    void pop() {
19        st.pop();
20        minVal.pop();
21    }
22
23    int top() { return st.top(); }
24
25    int getMin() { return minVal.top(); }
26};
27