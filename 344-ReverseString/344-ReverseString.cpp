// Last updated: 7/20/2026, 1:21:49 AM
1class Solution {
2public:
3    void reverseString(vector<char>& s) {
4        int i = 0;
5
6        int j = s.size() - 1;
7        while (i < j)
8            swap(s[i++], s[j--]);
9    }
10};