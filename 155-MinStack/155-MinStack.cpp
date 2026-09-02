// Last updated: 9/2/2026, 6:53:36 PM
1class MinStack {
2    stack<pair<int, int>> st;
3
4public:
5    MinStack() {}
6
7    void push(int value) {
8
9        if (st.empty()) {
10            st.push({value, value});
11        } else {
12            int curr = st.top().second;
13            st.push({value, min(value, curr)});
14        }
15    }
16
17    void pop() { st.pop(); }
18
19    int top() { return st.top().first; }
20
21    int getMin() { return st.top().second; }
22};
23