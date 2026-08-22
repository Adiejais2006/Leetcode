// Last updated: 8/22/2026, 4:22:14 PM
1class Solution {
2public:
3    bool checkDivisibility(int n) {
4        int s=0, p=1;
5        for(int x=n; x>0; x/=10){
6            const int r=x%10;
7            s+=r;
8            p*=r;
9        }
10        return n%(s+p)==0;
11    }
12};