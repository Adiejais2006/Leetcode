// Last updated: 9/3/2026, 9:56:40 PM
1class Solution {
2public:
3    string decodeString(string s) {
4        stack<char> st;
5        string ans = "";
6        for (auto it : s) {
7            if (it == ']') {
8                string repeat = "";
9                while (!st.empty() && st.top() != '[') {
10                    repeat += st.top();
11                    st.pop();
12                }
13                reverse(repeat.begin(), repeat.end());
14                st.pop();
15                string number = "";
16                while (!st.empty() && isdigit(st.top())) {
17                    number += st.top();
18                    st.pop();
19                }
20                reverse(number.begin(), number.end());
21                int no = stoi(number);
22                string temp = repeat;
23                while (--no) {
24                    repeat += temp;
25                    
26                }
27                for(char c:repeat)st.push(c);
28            } else
29                st.push(it);
30        }
31
32        while(!st.empty()){
33            ans+=st.top();
34            st.pop();
35        }
36        reverse(ans.begin(),ans.end());
37        return ans;
38    }
39};