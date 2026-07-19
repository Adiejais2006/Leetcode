// Last updated: 7/20/2026, 1:23:53 AM
1class Solution {
2public:
3    string reverseStr(string s, int k) {
4        int step = 2 * k;
5        for(int i = 0; i < s.length(); i += step){
6            int start = i;
7            int end = min(i + k - 1, (int)s.length() - 1);
8            while(start < end){
9                swap(s[start], s[end]);
10                start++;
11                end--;
12            }
13        }
14
15        return s;
16    }
17};