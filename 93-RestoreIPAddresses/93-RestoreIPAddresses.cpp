// Last updated: 11/3/2026, 12:09:49 AM
1class Solution {
2public:
3    vector<string> ans;
4
5    void solve(string& s, int idx, int parts, string curr) {
6
7        // Exactly 4 parts
8        if (parts == 4) {
9            if (idx == s.size()) {
10                curr.pop_back(); // Remove last dot
11                ans.push_back(curr);
12            }
13            return;
14        }
15
16        // Try segments of length 1, 2, 3
17        for (int len = 1; len <= 3; len++) {
18
19            if (idx + len > s.size()) break;
20
21            string temp = s.substr(idx, len);
22
23            // Leading zero condition
24            if (len > 1 && temp[0] == '0') break;
25
26            int num = stoi(temp);
27
28            if (num > 255) break;
29
30            solve(s, idx + len, parts + 1,
31                  curr + temp + ".");
32        }
33    }
34
35    vector<string> restoreIpAddresses(string s) {
36
37        if (s.size() < 4 || s.size() > 12)
38            return {};
39
40        solve(s, 0, 0, "");
41
42        return ans;
43    }
44};