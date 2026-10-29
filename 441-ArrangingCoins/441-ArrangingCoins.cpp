// Last updated: 10/29/2026, 8:20:00 PM
1class Solution {
2public:
3    int arrangeCoins(int n) {
4
5        long long low = 1 ;
6
7        long long sum = (long long)n*((long long)n+1)/2;
8
9        long long high = sum;
10        long long ans = 0;
11
12        while(low <=  high) {
13
14            long long mid = low + (high - low)/2;
15
16            long long val = (2LL*n)/(mid+1);
17
18            if(mid>val){
19                high = mid-1;
20            }
21            else {
22                ans = mid;
23                low = mid+1;
24            }
25        }
26        return high;
27        
28    }
29};