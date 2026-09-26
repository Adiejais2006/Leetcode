// Last updated: 9/26/2026, 2:48:29 PM
1class Solution {
2public:
3    int hammingWeight(int n) {
4        int cnt = 0;
5        string s;
6        while(n){
7            if(n&1){
8                s+='1';
9                n/=2;
10                cnt++;
11            }
12            else{
13                s+='0';
14                n/=2;
15            }
16        }
17       return cnt;
18    }
19};