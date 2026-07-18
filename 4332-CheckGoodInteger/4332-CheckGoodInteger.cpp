// Last updated: 7/18/2026, 1:58:31 PM
class Solution {
public:
    bool checkGoodInteger(int n) {
        int s1 = 0;
        int s2= 0 ;
        while (n != 0) {
            int digit = n % 10;
            s1 += digit;
            s2+= (digit*digit);
            n = n / 10;
        }
         

        if ((s2 - s1) >= 50)
            return true;
        return false;
    }
};