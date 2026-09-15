// Last updated: 9/15/2026, 3:28:25 PM
1class Solution {
2public:
3    int openLock(vector<string>& deadends, string target) {
4        string s = "0000";
5        unordered_set<string> st(deadends.begin(), deadends.end());
6        if (st.count(s))
7            return -1;
8        if (s == target)
9            return 0;
10        queue<pair<string, int>> q;
11        st.insert(s);
12        q.push({s, 0});
13        while (!q.empty()) {
14            auto node = q.front().first;
15            auto steps = q.front().second;
16            q.pop();
17            if (node == target)
18                return steps;
19            for (int i = 0; i < 4; i++) {
20                char orig = node[i];
21                node[i] = (orig == '9') ? '0' : orig + 1;
22                if (!st.count(node)) {
23                    st.insert(node);
24                    q.push({node, steps + 1});
25                }
26                node[i] = (orig == '0') ? '9' : orig - 1;
27                if (!st.count(node)) {
28                    st.insert(node);
29                    q.push({node, steps + 1});
30                }
31                node[i] = orig;
32            }
33        }
34        return -1;
35    }
36};