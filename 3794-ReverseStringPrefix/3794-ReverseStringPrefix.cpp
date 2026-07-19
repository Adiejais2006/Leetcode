// Last updated: 7/19/2026, 11:27:48 PM
1class Solution {
2public:
3    string reversePrefix(string s, int k) {
4        if (k == 1) {
5            return s;
6        }
7        int i = 0;
8        int j = k - 1;
9        while (i < j) {
10            swap(s[i], s[j]);
11            i++;
12            j--;
13        }
14        return s;
15    }
16};