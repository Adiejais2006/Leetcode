// Last updated: 9/6/2026, 5:08:06 PM
1class Solution {
2public:
3    int countSeniors(vector<string>& details) {
4
5        int cnt = 0;
6
7        for(const string& s : details) {
8            int age = (s[11] -'0') *10 +(s[12]-'0');
9
10            if(age > 60) {
11                cnt++;
12            }
13        }
14        return cnt;
15    }
16};