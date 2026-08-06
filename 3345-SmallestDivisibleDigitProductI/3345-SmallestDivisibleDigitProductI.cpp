// Last updated: 8/6/2026, 9:36:02 PM
1class Solution {
2public:
3    int product_digit(int x){
4        int ans=1, d=0;
5        for(; x; x/=10){
6            d=x%10;
7            ans*=d;
8        }
9        return ans;
10    }
11    int smallestNumber(int n, int t) {
12        int P[2]={product_digit(n/10), product_digit(n/10+1)};
13        int z0=((n/10)+1)*10;
14        for(int z=n; z<n+10; z++){
15            int p=P[z>=z0], d=z%10;
16            if (p*d%t==0) return z;
17        }
18        return 0;
19    }
20};