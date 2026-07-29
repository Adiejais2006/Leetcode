// Last updated: 7/29/2026, 8:19:44 PM
1class Solution {
2public:
3    int lengthOfLastWord(string s) {
4
5        int n = s.size();
6
7        int count = 0;
8        int pre = 0;
9
10        for(int i = 0; i < n; i++) {
11
12            if(s[i]==' ') {
13                if(count!=0) {
14                    
15                    pre = count;
16
17                }
18               
19                count = 0;
20            }
21            else {
22                count++;
23            }
24        }
25        if(count!=0) {
26            return count;
27        }
28        return pre;
29    }
30};