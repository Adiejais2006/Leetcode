// Last updated: 10/25/2026, 9:45:32 PM
1#include<bit>
2class Solution {
3public:
4    int calculateScore(int a, int b) {
5     int s1 = std::popcount(static_cast<unsigned int>(a));
6        int s2 = std::popcount(static_cast<unsigned int>(b));
7        if( s1>=s2) return s1*s2;
8        else return (s2/s1);
9    }
10};