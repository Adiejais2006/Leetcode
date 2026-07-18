// Last updated: 7/18/2026, 1:59:13 PM
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = n*n;
        int even = n*(n+1);
        return gcd(even,odd);
    }
};