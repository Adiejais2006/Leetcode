// Last updated: 10/31/2026, 10:29:49 PM
1class Solution {
2public:
3    int repeatedStringMatch(string a, string b) {
4        int n = a.length(), m = b.length(), cnt=0;
5        string repeated = "";
6        while(repeated.length() < m){
7            repeated += a;
8            cnt++;
9        }
10        if(repeated.find(b) != string::npos) return cnt;
11        repeated += a;
12        cnt++;
13        if(repeated.find(b) != string::npos) return cnt;
14        return -1;
15    }
16};