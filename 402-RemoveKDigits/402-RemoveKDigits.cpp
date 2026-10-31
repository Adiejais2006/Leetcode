// Last updated: 10/31/2026, 4:07:50 PM
1class Solution {
2public:
3    string removeKdigits(string num, int k) {
4        int n = num.size();
5        string ans = "";
6        stack<char> st;
7        for (int i = 0; i < n; i++) {
8            int number = num[i];
9            while (!st.empty() && st.top() > number && k > 0) {
10                st.pop();
11                k--;
12            }
13            st.push(num[i]);
14        }
15        while(!st.empty() && k>0){
16            st.pop();
17            k--;
18        }
19        if (st.empty())
20            return "0";
21        while (!st.empty()) {
22            ans += st.top();
23            st.pop();
24        }
25        reverse(ans.begin(), ans.end());
26        int i = 0;
27        while (ans[i] == '0') {
28            i++;
29        }
30        if(i==ans.size())return "0";
31        ans  = ans.substr(i);
32         return ans;
33    }
34};