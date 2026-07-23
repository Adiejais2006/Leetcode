// Last updated: 7/24/2026, 12:23:19 AM
1class Solution {
2public:
3    string makeFancyString(string s) {
4        int c=1;
5        string t="";
6        t+=s[0];
7        for(int i=1;i<s.size();i++) {
8            t+=s[i];
9            if(s[i]==s[i-1]) {
10                c++;
11            }
12            if(c>=3) {
13                t.pop_back();
14                c-=1;
15            }
16            if(s[i]!=s[i-1]) c=1;
17        }
18        return t;
19    }
20};