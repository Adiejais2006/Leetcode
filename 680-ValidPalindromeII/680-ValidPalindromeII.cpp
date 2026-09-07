// Last updated: 9/8/2026, 12:45:04 AM
1class Solution {
2public:
3    bool isPalindrome(const string& s, int l, int r) {
4        while (l < r) {
5            if (s[l] != s[r])
6                return false;
7            l++;
8            r--;
9        }
10        return true;
11    }
12
13    bool validPalindrome(string s) {
14        int l = 0, r = s.size() - 1;
15        while (l < r) {
16            if (s[l] != s[r]) {
17                bool removeleft = isPalindrome(s, l + 1, r);
18                bool removeback = isPalindrome(s, l, r - 1);
19                return removeleft || removeback;
20            }
21            l++;
22            r--;
23        }
24
25        return true;
26    }
27};