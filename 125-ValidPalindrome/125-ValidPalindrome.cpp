// Last updated: 7/20/2026, 1:19:25 AM
1class Solution {
2public:
3    bool isPalindrome(string s) {
4        int n = s.size();
5        int i = 0;
6        int j = n - 1;
7        while (i < j) {
8            while (i < j && !isalnum(s[i]))
9                i++;
10            while (i < j && !isalnum(s[j]))
11                j--;
12            if (tolower(s[i]) != tolower(s[j]))
13                return false;
14            i++;
15            j--;
16        }
17        return true;
18    }
19};