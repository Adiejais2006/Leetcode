// Last updated: 11/6/2026, 6:18:05 PM
1class Solution {
2public:
3    int openLock(vector<string>& deadends, string target) {
4        string start = "0000";
5        unordered_set<string> st(deadends.begin(), deadends.end());
6        if (st.count(start))
7            return -1;
8        if (start == target)
9            return 0;
10        queue<pair<string, int>> q;
11        q.push({start, 0});
12        st.insert(start);
13        while (!q.empty()) {
14            auto [node, moves] = q.front();
15            q.pop();
16            if (node == target)
17                return moves;
18            for (int i = 0; i < 4; i++) {
19                char orig = node[i];
20                node[i] = (orig == '9') ? '0' : orig + 1;
21                if (!st.count(node)) {
22                    st.insert(node);
23                    q.push({node, moves + 1});
24                }
25                node[i] = (orig == '0') ? '9' : orig - 1;
26                if (!st.count(node)) {
27                    st.insert(node);
28                    q.push({node, moves + 1});
29                }
30                node[i] = orig;
31            }
32        }
33        return -1;
34    }
35};