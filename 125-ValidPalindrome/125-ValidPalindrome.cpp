// Last updated: 7/20/2026, 1:15:10 AM
1class Solution {
2public:
3    bool isPalindrome(string s) {
4        string ans = "";
5        int n = s.size();
6        for (auto it : s) {
7
8            if (isalnum(it))
9                ans += tolower(it);
10        }
11        int i = 0;
12        int j = ans.size() - 1;
13        while (i < j) {
14            if (ans[i++] != ans[j--])
15                return false;
16        }
17        return true;
18    }
19};