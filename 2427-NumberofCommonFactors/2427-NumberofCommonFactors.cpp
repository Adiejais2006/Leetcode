// Last updated: 7/19/2026, 11:23:50 PM
1class Solution {
2public:
3    int commonFactors(int a, int b) {
4
5        int n;
6
7        if(a<=b) {
8            n=a;
9        }
10        else {
11            n=b;
12        }
13        int count = 1;
14
15        for(int i = 2; i <= n; i++) {
16            if(a%i==0 && b%i == 0) {
17                count++;
18            }
19
20        }
21        return count;
22        
23    }
24};