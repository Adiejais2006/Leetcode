// Last updated: 7/19/2026, 11:24:21 PM
1class Solution {
2public:
3    string reversePrefix(string s, int k) {
4
5        if(k==1) {
6            return s;
7        }
8        int  n = s.size();
9
10        int first = 0; 
11        int last = k-1;
12
13        while(first < last) {
14
15            char temp = s[first];
16            s[first] = s[last];
17            s[last]=temp;
18            first++;
19            last--;
20        }
21
22
23        return s;
24    }
25};