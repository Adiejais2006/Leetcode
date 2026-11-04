// Last updated: 11/4/2026, 6:33:25 PM
1class Solution {
2public:
3    int differenceOfSums(int n, int m) {
4        int sum1= 0 ;
5        int sum2= 0 ; 
6        for(int i = 1  ;i<=n ; i++){
7            if(i%m!=0) sum1+=i;
8            if(i%m==0) sum2+=i;
9        }
10        return sum1-sum2;
11    }
12};