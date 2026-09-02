// Last updated: 9/2/2026, 7:05:10 PM
1class Solution {
2public:
3    int evalRPN(vector<string>& tokens) {
4        stack<int> st;
5        for (auto it : tokens) {
6            if (it == "+") {
7                int one = st.top();
8                st.pop();
9                int two = st.top();
10                st.pop();
11                int number = one + two;
12                st.push(number);
13            } else if (it == "*") {
14                int one = st.top();
15                st.pop();
16                int two = st.top();
17                st.pop();
18                int number = one * two;
19                st.push(number);
20            } else if (it == "-") {
21                int one = st.top();
22                st.pop();
23                int two = st.top();
24                st.pop();
25                int number = two - one;
26                st.push(number);
27            } else if (it == "/") {
28                int one = st.top();
29                st.pop();
30                int two = st.top();
31                st.pop();
32                int number = two / one;
33                st.push(number);
34            } else
35                st.push(stoi(it));
36        }
37        return st.top();
38    }
39};