// Last updated: 11/4/2026, 6:11:04 PM
1class Solution {
2public:
3    string maximumOddBinaryNumber(string s) {
4        int n = s.size();
5        int ones = 0 ;
6        for(auto it:s){
7            if(it=='1') ones++;
8        }
9        s[n-1]='1';
10        ones--;
11        int i = 0 ;
12        while(ones>0 && i < n){
13            s[i++] = '1';
14            ones--;
15        }
16        while(i<n-1){
17            s[i++] = '0';
18        }
19        return s;
20    }
21};