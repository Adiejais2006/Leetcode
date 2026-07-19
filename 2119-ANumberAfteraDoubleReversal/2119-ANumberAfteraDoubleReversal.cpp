// Last updated: 7/19/2026, 11:23:40 PM
1class Solution {
2public:
3    bool isSameAfterReversals(int num) {
4
5        if(num==0) {
6            return true;
7        }
8        string str = to_string(num);
9
10        int no = str.size();
11
12        if(str[no-1]=='0') {
13            return false;
14        }
15        return true;
16        
17    }
18};