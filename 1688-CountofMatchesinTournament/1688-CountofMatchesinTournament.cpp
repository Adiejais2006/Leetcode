// Last updated: 11/2/2026, 11:37:53 PM
1class Solution {
2public:
3    int numberOfMatches(int n) {
4        int ans = 0 ;
5        while(n!=1){
6            if(n%2==1){
7                ans += (n-1)/2;
8                n = (n-1)/2 + 1 ;
9            }
10            else {
11                ans+=n/2;
12                n=n/2;
13            }
14        }
15        return ans;
16    }
17};