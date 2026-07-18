// Last updated: 7/18/2026, 1:59:09 PM
class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0;
         long long power = 1;
        while (n != 0) {
             long long r = n % 10;
            if (r != 0) {
                ans = ans + r * (power);
                power *= 10;
            }
            n = n / 10;
        }

        return ans;
    }
};