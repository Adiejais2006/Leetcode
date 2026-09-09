// Last updated: 9/9/2026, 12:29:14 PM
1class Solution {
2public:
3    long long countCommas(long long n) {
4        if(n <= 999) return 0;
5
6        long long totalCommas = 0;
7        long long rangeStart = 1000;
8        long long rangeEnd = rangeStart * 1000 - 1;
9        int commas = 1;
10
11        while(rangeStart <= n){
12            long long numbers = (min(n, rangeEnd) - rangeStart + 1);
13            totalCommas += 1LL * commas * numbers;
14
15            if(rangeEnd > n) break;
16
17            rangeStart = rangeStart * 1000;
18            rangeEnd = rangeStart * 1000 - 1;
19            commas++;
20        }
21        return totalCommas;
22    }
23};