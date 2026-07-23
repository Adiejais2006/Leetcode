// Last updated: 7/24/2026, 12:25:23 AM
1class Solution {
2public:
3    string clearDigits(string s) {
4        string t="";
5        for(char x:s) {
6            if(x>='0' && x<='9') t.pop_back();
7            else t+=x;
8        }
9        return t;        
10    }
11};