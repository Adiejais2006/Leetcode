// Last updated: 9/4/2026, 5:18:20 PM
1class Solution {
2public:
3    int calculate(string s) {
4        long long result = 0;
5         long long number = 0;
6         long long sign = 1;
7        stack<int> st;
8        for (char it : s) {
9            if (isdigit(it)) {
10                number = number * 10 + (it - '0');
11            } else if (it == '+') {
12                result += sign * number;
13                number = 0;
14                sign = 1;
15            } else if (it == '-') {
16                result += sign * number;
17                number = 0;
18                sign = -1; 
19            } else if (it == '(') {
20                st.push(result);
21                st.push(sign);
22                result = 0;
23                sign = 1;
24            } else if (it == ')') {
25                result += sign * number;
26                number = 0;
27                 long long prevSign = st.top();
28                st.pop();
29                 long long prevResult = st.top();
30                st.pop();
31                result = prevResult + prevSign * result;
32            }
33        }
34        result += sign * number;
35        return (int)result;
36    }
37};
38