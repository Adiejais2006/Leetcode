// Last updated: 7/18/2026, 2:07:39 PM
class Solution {
public:
    int divide(int dividend, int divisor) {
          if (dividend == INT_MIN && divisor == -1) return INT_MAX;

     
        bool isPositive = (dividend < 0) == (divisor < 0);

        
        long long n = abs((long long)dividend);
        long long m = abs((long long)divisor);

        long long result = 0;

     
        while (n >= m) {
            long long temp = m, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            result += multiple;
        }

    
        return isPositive ? result : -result;
    }
};