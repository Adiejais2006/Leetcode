// Last updated: 7/19/2026, 11:24:28 PM
1class Solution {
2public:
3    int firstMatchingIndex(string s) {
4        
5        int left = 0;
6
7        int right = s.size()-1;
8
9        while(left<=right) {
10
11            if(s[left]==s[right]) {
12                return left;
13            }
14            left++;
15            right--;
16        }
17        return -1;
18    }
19};