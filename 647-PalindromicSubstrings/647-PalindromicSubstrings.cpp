// Last updated: 10/22/2026, 1:26:49 PM
1class Solution {
2    bool is(string a) {
3        string b = a;
4        reverse(b.begin(), b.end());
5        return a == b;
6    }
7public:
8    int countSubstrings(string s) {
9        int n = s.size();
10        int cnt = 0 ; 
11        for (int i = 0; i < n; i++) {
12            string a = "";
13            for (int j = i; j < n; j++)  {
14                a+=s[j];
15                if(is(a)) cnt++;
16            }
17        }
18        return cnt;
19    }
20};