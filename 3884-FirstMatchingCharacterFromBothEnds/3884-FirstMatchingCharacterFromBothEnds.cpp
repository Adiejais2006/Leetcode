// Last updated: 7/19/2026, 11:29:16 PM
1class Solution {
2public:
3    int firstMatchingIndex(string s) {
4        int l = 0;
5        int r = s.size()-1;
6        while(l<=r) {
7            if(s[l]==s[r]) {
8                return l;
9            }
10            l++;
11            r--;
12        }
13        return -1;
14    }
15};