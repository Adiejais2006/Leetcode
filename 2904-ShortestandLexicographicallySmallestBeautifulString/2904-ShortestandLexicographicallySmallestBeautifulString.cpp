// Last updated: 8/26/2026, 9:07:08 PM
1class Solution {
2public:
3    string shortestBeautifulSubstring(string s, int k) {
4        string ans = "";
5        int n = s.size();
6
7        for (int i = 0; i < n; i++) {
8
9            int oneCnt = 0;
10            string cur = "";
11
12            for (int j = i; j < n; j++) {
13
14                cur += s[j];
15
16                if (s[j] == '1')
17                    oneCnt++;
18
19                // More than k ones can never become valid again
20                if (oneCnt > k)
21                    break;
22
23                if (oneCnt == k) {
24
25                    if (ans == "" ||
26                        cur.size() < ans.size() ||
27                        (cur.size() == ans.size() && cur < ans)) {
28
29                        ans = cur;
30                    }
31                }
32            }
33        }
34
35        return ans;
36    }
37};